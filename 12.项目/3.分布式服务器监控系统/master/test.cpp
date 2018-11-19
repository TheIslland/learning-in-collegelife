/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月18日 星期日 15时43分29秒
 ************************************************************************/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include <iostream>

using namespace std;

#define MAX_NODE_DATA_SIZE 65535
#define MAX_QUEUE_NODE_COUNT 32

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef struct buffer_node_{
    uint16_t dataLen;
    uint8_t data[MAX_NODE_DATA_SIZE];
} buffer_node_t;

typedef struct buffer_queue_{
    buffer_node_t queue[MAX_QUEUE_NODE_COUNT];
    int front;
    int rear;
    bool Init(){
        front = rear = 0;
        memset(queue, sizeof(buffer_node_t)*MAX_QUEUE_NODE_COUNT, 0);
    }
    bool isEmpty(){
        return (rear == front);
    }
    bool isFull(){
        return ((rear+1)%MAX_QUEUE_NODE_COUNT == front);
    }
    bool Enqueue(buffer_node_t *node){
        if(isFull()){
            return false;
        }
        memcpy(&queue[rear], node, sizeof(buffer_node_t));
        rear = (rear+1)%MAX_QUEUE_NODE_COUNT;
        return true;
    }
    buffer_node_t* Dequeue(){
        if(isEmpty()){
            return NULL;
        }
        buffer_node_t* node = &queue[front];
        front = (front+1)%MAX_QUEUE_NODE_COUNT;
        return node;
    }
}buffer_queue_t;

typedef struct buffer_manage_{
    buffer_queue_t sendQueue;
    buffer_queue_t receiveQueue;
    void buffer_init_(){
        sendQueue.Init();
        receiveQueue.Init();
    }
} buffer_manage_t;

buffer_manage_t *bufferManage = NULL;
int bufferID = 0;

bool Create_ShareMem(){
    key_t k;
    printf("size is %lu/n",sizeof(buffer_manage_t));
    bufferID = shmget(k = ftok("./tsm3", 1), sizeof(buffer_manage_t), IPC_CREAT);
    printf("k is %d/n",k);
    if(bufferID == -1){
        printf("Create_ShareMem shmget failed errno = %d, error msg is %s/n", errno,strerror(errno));
    }
    printf("Create_ShareMem shmget bufferID = %d, error = %d/n", bufferID, errno);
    bufferManage = (buffer_manage_t*)shmat(bufferID, 0, 0);
    printf("Create_ShareMem shmget bufferManage = %p, error = %d/n", bufferManage, errno);
    if(bufferManage == (void *) -1 || bufferManage == NULL){
        bufferManage = NULL;
        printf("Create_ShareMem shmat failed errno = %d", errno);
        return false;
    }
    bufferManage->buffer_init_();
    return true;
}

bool Delete_ShareMem(){
    if((shmdt(bufferManage) != 0)){
        printf("Delete_ShareMem shmdt failed errno = %d", errno);
    }
    if(shmctl(bufferID, IPC_RMID, 0) != 0){
        printf("Delete_ShareMem shmctl failed errno = %d", errno);
        return false;
    }
    return true;
}

bool ShareMem_AddData(uint8_t* data, uint16_t dataLen) {
    bool ret = false;
    buffer_node_t* node;
    node = (buffer_node_t*)malloc(sizeof(buffer_node_t));
    memset(node, 0, sizeof(buffer_node_t));
    node->dataLen = dataLen;
    if(node->dataLen > MAX_NODE_DATA_SIZE)
        node->dataLen = MAX_NODE_DATA_SIZE;
    if(data != NULL){
        memcpy(node->data, data, node->dataLen);
    }
    if(bufferManage != NULL){
        bufferManage->receiveQueue.Enqueue(node);
        ret = true;
    }
    return ret;
}

bool ShareMem_RemoveData(uint8_t** data, uint16_t* dataLen) {
    bool ret = false;
    if(bufferManage != NULL){
        buffer_node_t* node = NULL;
        //bufferManage->sendQueueProtected.Lock();
        node = bufferManage->sendQueue.Dequeue();
        if(node != NULL){
            *data = (uint8_t*)malloc(node->dataLen);
            if(*data != NULL){
                memcpy(*data, node->data, node->dataLen);
                *dataLen = node->dataLen;
                ret = true;
            }
        }
    //bufferManage->sendQueueProtected.Unlock();
    }
    return ret;
}

void printData() {
    for(int i = bufferManage->receiveQueue.front; i < bufferManage->receiveQueue.rear; i++) {
        printf("idx is %d,data is %s/n",i,bufferManage->receiveQueue.queue[i].data);  
    }
}

int main() {
    Create_ShareMem();
    while(1){
        uint8_t fromT1[10] = "123456789"; ShareMem_AddData(fromT1, 10);
        printf("%u\n", fromT1[0]);
        printData();
        sleep(1);
        //ShareMem_RemoveData();
    } Delete_ShareMem();
    return 0;
}


