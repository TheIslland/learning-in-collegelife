# 项目：实现自己的malloc

## 一、需求

* 实现自己的申请内存函数`malloc`；
* 实现自己的内存释放函数`free`；
* 实现自己的初始化嫩存申请函数`calloc`
* 实现自己的内存扩容函数`realloc`

## 二、实现思路

* 采用的数据结构：链表

  每一个信息头记录他后面所申请的空间相关信息，并指向下一信息头

  ```c
  typedef struct __metadata {
      size_t size; //代表所申请的空间大小
      size_t free; //大小为size的空间是否被占用
      struct __metadata *next; //前驱
      struct __metadata *prev; //后继
      void *begin; //存储空间首地址
  } MetaData, *pMetaData;
  ```

  

* 可变分区管理方法：最先适应

  * 思路：顺序查找未分配区的链表，选择第一个能满足长度要求的分区。
  * 优点：未分配区表中的空闲区往往按照地址从低到高排列，这样搞地质部分的内存尽量不被分割， 可以被留给内存需求大的进程。
  * 缺点：低地址空间的使用率远高于高地址空间并在低地址空间产生了许多小的未分配区。

* `malloc`实现思路

  * 当内存未申请是初始化信息头申请空间
  * 在信息头中查找合适的空内存区，如果找到合适的较大内存区，先切分后占用，反之直接占用
  * 如果在所有信息头中都没有找到合适的内存区，则通过`sbrk`直接项系统申请内存
  * 

* 

## 三、代码实现

* ```c
  #include "malloc.h"
  /*Modify Any parts above is illegal*/
  
  /*只准修改以下内容 否则零分处理*/
   
  //malloc存储信息头，结构体
  typedef struct __metadata {
      size_t size; //后接申请空间大小
      size_t free; //大小为size的空间是否被占用
      struct __metadata *next; //前驱
      struct __metadata *prev; //后继
      void *begin; //存储空间首地址
  } MetaData, *pMetaData;
   
  static pMetaData __memory_head = NULL; //当前进程空间信息头
   
  void print_log(char *str) {
      printf("[%s:%d]: %s\n", __func__, __LINE__, str);
      fflush(stdout);
  }
  
  //结构体初始化
  static void initMetaData(pMetaData p, size_t size, size_t free, pMetaData prev, pMetaData next) {
      p->size = size;
      p->free = free;
      p->prev = prev;
      p->next = next;
      p->begin = ((char *)p) + sizeof(MetaData);
  }
  
  //realloc时将元素从src空间拷贝至dest空间
  static void dataCopyTo(void *dest, void *src, size_t len) {
      size_t i;
      char *p1 = (char *)dest;
      char *p2 = (char *)src;
      for (i = 0; i < len; ++i) {
          p1[i] = p2[i];
      }
      return ;
  }
  
  //malloc函数的实现
  void *mylloc(size_t sizes){
      pMetaData p, q;
      size_t msize = sizes + sizeof(MetaData); //新申请空间所需占空间大小
      if (__memory_head == NULL) { //如果空间尚未初始化，进行初始化操作
          p = sbrk(0); //sbrk（0）获取当前进程空间brk_end尾地址并让p指向他
          if (sbrk(msize) == (void *)-1) { //如果无法申请msize大小直接返回NULL
              return NULL;
          }
          initMetaData(p, sizes, 0, NULL, NULL); //初始化p为后有size大小空间被使用，无前驱与后继的信息头
          __memory_head = p; //让记录头等于p（更新记录头）
      } else {
          p = __memory_head; //初始化p为记录头
          while (p) { //从记录头向后寻找知道无法找到
              if (p->free && p->size >= msize) { //如果当前段没被使用且当前段可用大小比需求空间大，进行切分操作
                  q = (pMetaData)(((char *)p->begin) + sizes); //让q节点为当前端空间后，用于记录剩余空间信息
                  initMetaData(q, p->size - msize, 1, p, p->next); // 初始化q
                  p->size = sizes;
                  if (p->next !=NULL) { //如果当前段后继有信息头，更新其前驱信息
                      p->next->prev = q;
                  }
                  p->next = q; //更新当前段后继信息
                  p->free = 0; //更新当前段占用信息
                  break; //成功申请内存跳出
              } else if (p->free && p->size >= sizes) { //如果当前端空闲且空间比申请空间略大但不足以用于分割
                  p->free = 0; //占用当前段
                  break; //成功申请退出
              }
              if (p->next == NULL) break; //在所有信息头里寻找不到合适空间段，跳出
              p = p->next; //当前段空间大小较小寻找下一个
          }
          if (p->next == NULL) { //如果在已有信息头中没有合适的，则进行新空间申请
              q = sbrk(0); //sbrk（0）获取当前的brk_end
              if (sbrk(msize) == (void *)-1) { //如果无法申请返回NULL，sbrk（msize）将brk_end扩展至q+msize
                  return NULL;
              }
              initMetaData(q, sizes, 0, p, NULL); //初始化q
              p->next = q; //更新后继
              p = q; //更新p为新节点
          }
      }
      return p->begin;
  }
  
  //内存释放函数
  void myfree(void *p){
      pMetaData q, k;
      q = (pMetaData)(((char *)p) - sizeof(MetaData)); //初始化q为p的信息头
      q->free = 1; //将信息头状态更改为为使用
      if (q->prev && q->prev->free) { //如果前驱段与当前段双空，则合并
          k = q->next;
          q = q->prev;
          q->size += q->next->size + sizeof(MetaData);
          q->next = k;
          if (k != NULL) {
              k->prev = q;
          }
      }
      if (q->next != NULL && q->next->free) { //如果后继段与当前段双空，则合并
          k = q->next->next;
          q->size += q->next->size + sizeof(MetaData);
          q->next = k;
          if (k != NULL) {
              k->prev = q;
          }
      }
      size_t msize; 
      if (q->next == NULL) { //如果当前段为尾段，则释放他回收空间
          if (q->prev != NULL) { //如果有前驱则前驱的后继指向空
              q->prev->next = NULL;
          } else { //如果没有前驱则回复记录头为空
              __memory_head = NULL;
          }
          msize = q->size + sizeof(MetaData); //计算即将释放的尾信息头和其空间大小
          sbrk(-msize); //回收空间
      }
  }
  
  //calloc函数的实现
  void *mycalloc(size_t numitems, size_t size){
      void *ret = mylloc(numitems * size); //先申请malloc
      char *p = (char *)ret; //将空间转化为char *型
      size_t i = numitems * size; //计算需要归零的个数
      while (i--) {
          (*p) = 0;
          ++p;
      }
      return ret;
  }
  
  //realloc
  void *myrealloc(void *ptr, size_t size){
      pMetaData p, q, k;
      p = (pMetaData)(((char *)ptr) - sizeof(MetaData)); //初始化p为ptr(输入指针)的信息头
      if (p->size >= size) return p->begin; //如果当前段空间比重申请空间大则直接返回
      if (p->next == NULL) { //如果当前节点为尾节点，则可以直接向系统再申请空间
          if (sbrk(size - p->size) == (void *)-1) { //向系统空间申请原空间不够存储的空间
              return NULL;
          }
          p->size = size; //更新空间大小
      }
      if (p->size < size && p->next && p->next->free) { //如果当前空间比申请空间小且有后继且后继未被占用
          if (p->size + p->next->size >= size) { //如果合并后的大小比重新申请的空间大切分
              q = (pMetaData)(((char *)p->begin) + size); //初始化q为信息头
              initMetaData(q, p->size + p->next->size - size, 1, p, p->next->next);
              p->next = q;
              p->size = size;
          } else if (p->size + p->next->size + sizeof(MetaData) >= size) { //如果合并后的大小和需求大小正好相等
              p->size = p->size + p->next->size + sizeof(MetaData); //更新合并后大小
              q = p->next->next; //更新next指针
              p->next = q;
              if (q != NULL) {
                  q->prev = p;
              }
              p->size = size;
          }
      }
      if (p->size < size && p->prev && p->prev->free) { //如果当前空间不足，但前驱节点存在且未使用
          if (p->size + p->prev->size >= size) { //如果合并后的大小比重新申请的空间大切分
              q = p->next;
              p = p->prev;
              size_t ksize = p->size + p->next->size - size; //向前合并后并剩余空间大小
              dataCopyTo(p->begin, p->next->begin, p->next->size); //将内容从p的后继合并至p
              k = (pMetaData)(((char *)p->begin) + size); //初始化剩余空间信息头
              initMetaData(k, ksize, 1, p, q); //初始化剩余空间大小信息头k
              p->next = k; 
              if (q != NULL) {
                  q->prev = k;
              }
              p->size = size;
              p->free = 0;
          } else if (p->size + p->prev->size + sizeof(MetaData) >= size) { //如果合并后大小正好，不切分
              q = p->next;
              p = p->prev;
              size_t totalsize = p->size + p->next->size + sizeof(MetaData);
              dataCopyTo(p->begin, p->next->begin, p->next->size);
              p->next = q;
              if (q != NULL) {
                  q->prev = p;
              }
              p->size = totalsize;
              p->free = 0;
          }
      }
      if (p->size < size) { //如果没有合适空间
          void *ret = mylloc(size); //申请size大小
          if (ret == NULL) return NULL;
          dataCopyTo(ret, p->begin, p->size);
          myfree(p->begin); //回收冗余空间
          p = (pMetaData)(((char *)ret) - sizeof(MetaData));
      }
      return p->begin;
  }
  /*只准修改以上内容 否则零分处理*/
  /*Modify Any parts below is illegal*/
  ```

* 