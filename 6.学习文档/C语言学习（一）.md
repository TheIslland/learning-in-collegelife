

# C语言学习

## 语言入门基础

* ### **输出函数**

  * 函数是一个黑箱子，给予一个输入会返回一个输出，函数完成了一个映射，数组是一个展开的函数。 函数比数组节省了空间，数组被称为纪录式，函数是一种计算式个数

* #### **`printf`函数**

  * 头文件 ：`stdio.h`

  * 原型：`int printf(const char *format, ...);`

  * format :格式控制字符串

  * ...:可变参数列表

  * 返回值：成功输出的字符个数

  * ```c
    #include<stdio.h>
    int main() {
    	int n = printf("Hello world!\n");
        printf("success print char num is %d\n", n);
        return 0;
    }
    ```

* #### **`scanf`函数**

  * 返回值为：当成功读入时返回值为的成功读入的参数个数，当读入错误时返回值为0，当遇到错误或者返回`EOF`时返回-1（`EOF`的值为—1）

  * `printf`获取数字位数

    ```c
    #include<stdio.h>
    int main() {
        int n;
        scanf("%d", &n);
        printf("has %d digit\n", printf("%d", n));
        return 0;
    }
    ```

  * `printf`获取输出字符个数

    ```c
    #include<stdio.h>
    int main() {
        char a[100];
        scanf("%[^\n]s", a);
        printf(" length is %d\n", printf("%s", a));
        return 0;
    }
    ```

  * 

* #### **`sprintf`函数**

  * 功能：向一个字符串中打印格式控制字符串。

  * 函数`format`:字符串输出函数`sprintf(target string, format string, data)`。

  * ```c
    int a, b, c, d;
    char str[1000];
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sprintf(str, "%d.%d.%d.%d\n", a, b, c, d);
    ```

  * 

* #### **`fprintf`函数**

  * 功能将格式控制字符串写入到文件中

  * `format`：`fprintf(File pointer, format string, data);`

  * ```c
    File *fd = fopen("test", "wb");
    fprintf(fd, "%s", "test success\n");
    ```

  * 在终端执行程序时：

    `stdin（Standardinput）`标准输入 0

    `stdout（Standardoutput）`标准输出 1

    `stderr（Standarderror）`标准错误 2

  

## 数学运算

* ### C语言基本运算符

  * | 运算符  |     说明     |               例子                |
    | :-----: | :----------: | :-------------------------------: |
    |    =    |  赋值运算符  |              a = b;               |
    | + - × / | 基本四则运算 |         a = (b + c) * d;          |
    |    %    |  求余运算符  | (a + b) %c = (a % c + b % c) % c; |
    | &\| ^ ~ |   位运算符   |           a = ~b \| c;            |
    | <<、>>  |   左移右移   |            a = b >> 2;            |

    

* ### C语言常用数学函数（`<math.h>`）

  | 常用函数           | 常用函数   |
  | ------------------ | ---------- |
  | `pow(a, n)`        | `fabs(n)`  |
  | `sqrt(n)`          | `log(n)`   |
  | `ceil(n)`          | `log10(n)` |
  | `floor(n)`         | `acos(n)`  |
  | `abs(n)(stdilb.h)` | ...        |

  * 常用小技巧：

    *  $log_a{b} = \frac{log_c{b}}{log_c{a}}$
    * $acos（-1）= \pi$

    * 如何求一个函数的立方跟$pow（n,\frac{1}{3}）$
    * 角度值到弧度值$\frac{x}{180} × acos（-1）$

## 密训

sqrt（）自我实现

二分值

```c
#include <stdio.h>
#define EPS 1e-10
double _sqrt1(double x) {
	double head = -100, tail = 100, mid;
    while (tail - head > EPS) {
        mid = (head + tail) / 2.0;
        if (mid * mid < x)head = mid;
        else tail = mid;
    }
    return head;
}
int main() {
    double x;
    while (scanf("%lf", &x) != EOF) {
	printf("%lf\n", _sqrt1(x));
    }
    return 0;
}
```

牛顿迭代法

```c
#incldue<stdio.h>
#include<math.h>
#include <time.h>
double f1(double x, double n) {
	return x * x - n;
}
double f1_prime(double x) {
    return 2 * x;
}
double newton(double n, double (*f1)(double, double), double (*f1_prime)(double)) {
	double x = 1.0; //基础值
    #define EPS 1e-7
    while (fabs(f(x) - n) > EPS) {
		x -= f(x,n) / f_prime(x);
    }
    return x;
}
int main() {
 	double x;
    while (scanf("%lf", &x) != EOF) {
	printf("%lf\n", _sqrt1(x));
    printf("%lf\n", newton(x,f1,f1prime));
    }
	return 0;
}
```

牛顿迭代法

x0 = f（）

```c
//宏定义运行时间
#define TEST_TIME(func) ({\
	int begin = clock();\
	double ret = func;\
	int end = clock();\
	printf("%lfms\n", (end - begin) *1.0 / CLOCKS_PER_SEC * 1000);\
})
```

o(1)sqrt雷神之锤

```c
float SqrtByBisection(float n) //用二分法 
{ 
	if(n<0) //小于0的按照你需要的处理 
		return n; 
	float mid,last; 
	float low,up; 
	low=0,up=n; 
	mid=(low+up)/2; 
	do
	{
		if(mid*mid>n)
			up=mid; 
		else 
			low=mid;
		last=mid;
		mid=(up+low)/2; 
	}while(abs(mid-last) > eps);//精度控制
	return mid; 
} 
```



## 程序流程控制方法

**c语言关系运算符**

| 运算符 | 说明               | 例子              |
| ------ | ------------------ | ----------------- |
| ==     | 等于               | a == b            |
| ！=    | 不等于             | a ！=b            |
| <、>   | 小于和大于         | a > b、a < b      |
| <=、>= | 小于等于，大于等于 | a >=b 、a <=b     |
| !      | 非                 | ！（0）！（NULL） |





**`！！（x）` 归一化！？？？？**

**注意：**

​	1.`a = b`的返回值为b

​	2.任何表达式都是有返回值的

## if语句

## switch语句

switch语句以default作为其他判断项

**在工程代码中写switch一定要写default防止出现意外bug**

## 加餐

```c
   // #define likely(x) __builtin_expect(!!(X), 1);
    // #define unlikely(x) __builtin_expect(!!(x), 0);
    // likely 是经常成立 unlikely 是不经常成立，为什么写这两局呢？
    // 人工判断后写入判断进行提速

```



## 函数

**1.函数是压缩的数组，数组是展开的函数**

```c
//K&R风格的函数定义，现已不用，g++编译不过
int is_prime(x) //声明返回值类型和函数名
int x; //声明传入参数类型
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
```

**2.递归函数**

1.明确递归函数的语义

2.边界条件处理

3.针对于问题的**处理过程**和**递归过程**

4.设计结果返回

**函数指针**

只要是被加载进内存的数据就有地址

./a.out->数据

证明gcd(a,b) <=> gcd (b, a % b)

c = gcd(a,b) 

=> a = kb + c

=> c = a - kb

a = xc, b = yc => gcd(x, y) = 1

=>a % b = r = xc - yck = (x - yk)c 

证明gcd（x - ky, y) = d

x - ky = n * d

y = md

x = n * d  + ky = nd+kmd

gcd(x,y) >= d

x = (n + km)d

y = md

## 变参函数

销毁va_族

va_list 类型的变量

va_start va_start(va_列表, 变参列表的前一个参数 )

va_arg 取值？？？？？

va_end销毁

实现变参函数max_int

```c
#include <stdio.h>
#include <stdarg.h>

int max_int(int num, ...) {
    int ans = 0, temp;
    va_list arg;//定义一个代表参数列表的变量
    va_start(arg, num);//初始化参数列表
    while (num--) {
        temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }//循环读入num个参数，取出其中的最大值，放到ans变量中
    va_end(arg);//释放参数列表
    return ans;
}

int main() {
    printf("%d\n",max_int(3, 1, 5, 3));
    printf("%d\n",max_int(2, 1, 3));
    printf("%d\n",max_int(6, 6, 5, 3, 7, 9, 10));
    printf("%d\n",max_int(3, 1, 9, 10));
    return 0;
}
```

int is_prime(int x); // 函数声名
//如果不定移is_prime则不可以生成可执行文件
//但可以加入 -c 生成对象文件
//但是函数可以在其他文件中定义，编译然后连接编译每个.o文件

## 数组于预处理命令

1.数组代表着一片连续的存储空间。

2.数组的主要作用是映射

**!数组是展开的函数!**

#### 数组与地址

1.char指针可以存储int型地址，但要进行类型转换。

2.数组的映射顺序是反向的，低位在前，高位在后

## 预处理命令-宏定义

定义符号常量：

```c
#define PI 3.1415926
#define MAX_N 10000
```

定义傻瓜表达式：

仅仅将前部分替换到后部分

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define s(a, b) a * b
```

定义代码段：

**定义代码段时要在行尾添加`\`**

```c
#define p(a) {\
	printf("%d\n", a);\
	return 0;
}
```

**预处理命令-预定义的宏**

| 宏                    | 说明                    |
| --------------------- | ----------------------- |
| `_DATA_`              | 日期：Mmm dd yyyy       |
| `__TIME__`            | 时间: hh:mm:ss          |
| `__LINE__`            | 行号                    |
| `__FILE__`            | 文件名                  |
| `__func__`            | 函数名/非标准           |
| `__FUNC__`            | 函数名/非标准           |
| `__PRETTY_FUNCTION__` | 更详细的函数信息/非标准 |
|                       |                         |

**预处理命令-条件式编译**

| 函数             | 说明               |
| ---------------- | ------------------ |
| #ifdef DEBUG     | 是否定义了DEBUG宏  |
| #ifndef DEBUG    | 是否没定义DEBUG宏  |
| #if MAX_N == 5   | 宏MAX_N是否等于5   |
| #elif MAX_N == 4 | 否则宏MAX是否等于4 |
| #else            |                    |
| #endif           |                    |

```c
#include <stdio.h>

#ifdef DEBUG
#define P printf("%s : %d\n", __func__, __LINE__)
#else
#define P
#endif

void testfunc() {
    P;
}

int main() {
    P
	testfunc();
    return 0;
}
```



## 复杂结构与指针

**当结构体申请内存时会以结构体中最大的单元作为每种类型申请的标准单元**

```c
struct node1 {
    char a;
    char b;
    int c;
} //总计占用8个字节，两个单元
```

```c
struct node2 {
    char a;
    int c;
    char b;
} //总计占用12个字节，三个单元
```

## 共用体

**公用一块存储空间**

```c
union register {
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    }bytes;
  	unsigned int number;  
};
```

## **可用不同类型查看不同结果**

用共用体实现ip转整数

```c
#include <stdio.h>

union IP {
	struct {
		unsigned char arr[4];
    } ip;
	unsigned int num;
};

int main() {
    IP ip;
    int a, b, c, d;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
    	ip.ip.arr[0] = a;
    	ip.ip.arr[1] = b;
    	ip.ip.arr[2] = c; 
        ip.ip.arr[3] = d;
		printf("%d\n", ip.num);
    }
}
```

**字符型存整形上限是174，无符号性是255**

## 指针

任何一个变量都有一个地址

指针变量是存储地址的

64位系统中为8个字节，32位系统中4个字节（多少位系统是计算机内存的寻址空间）

指针的类型影响的是在解析运算符下指针的行为方式

不管是什么类型的指针都只占8个字节

scanf函数

​	头文件`stdio.h`

​	原型：int scanf(const char *fomat, ...);

​	函数区分传入参数和传出参数（传出参数需要传入参数地址）

​	

### 指针等价形式转换

__*p <=> a(原始变量)__

__p + 1 <=> &p[1]__

__p->filed <=> (*p).filed <=> a.filed__



```c
struct Data {
	int x, y;
};
struct Data a[2], *p = a;
请用尽可能多的形式表示ａ[1].x
*(p + 1).x 
a[1].x 
*(a + 1).x
(a + 1)->x 
(p + 1)->x 
*p[1].x
(&a[1])->x
```

## 函数指针

`int (*add) (int, int);` 定义的是一个指针变量

`typedef int (*add)(int, int);`　定义的是一个指针类型

```c
//建类型的重命名：
typedef long long lint
//结构体类型的重命名：
typedef struct __node{
	int x, y;
} Node, *PNode;

//函数指针命名：
typedef int (*func)(int);
```



MAIN函数参数

int main();

int main(int argc, char *argv[]);

int main(int argc, char *argv[], char **env);

第一个参数是参数个数，第二个参数数命令行参数，第三个是环境变量

# 项目要求





















