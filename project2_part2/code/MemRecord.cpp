#include <stdio.h>
#include<stdlib.h>
#include <cstring>
#include <string>
#include <unordered_map>
#include "MemRecord.h"
#include<fstream>
#include<iostream>
#include <iomanip>
using namespace std;

MemoryInfo* beginNode = (MemoryInfo*) malloc(sizeof(MemoryInfo));
MemoryInfo* endNode = (MemoryInfo*) malloc(sizeof(MemoryInfo));
fstream f;
fstream fr;

MemAllocate::MemAllocate(char const* _file,int _line){
    this->file=_file;
    this->line=_line;
}

template <class T> inline T* MemAllocate::operator*(T* p){
    MemoryInfo* change = rfind(p);
    change->file=this->file;
    change->line=this->line;
    printAllocLog(change);
    return p;
}

void* operator new(size_t  size){
    void* m=malloc(size);
    // printf("From new: pointer %p is add\n",m);
    allocate(m,size);
    return m;
}

void* operator new[](size_t  size){
    void* m=malloc(size);
    // printf("From new[]: pointer %p is add\n",m);
    allocate(m,size);
    return m;
}

void* Demalloc(size_t size){
    void* m=malloc(size);
    allocate(m,size);
    return m;
}

void* Decalloc(size_t num,size_t size){
    void* m=calloc(num,size);
    allocate(m,num*size);
    return m;
}

void* Derealloc(void* ptr,size_t size){
    MemoryInfo* tem = rfind(ptr);
    void*m;
    if(tem->size<size){
        m = realloc(ptr,size);
        printFreeLog(tem);
        deleteMemoryInfo(tem);
        // printf("small\n");
        allocate(m,size);
    }
    else{
        // printf("not");
    }
    return m;
}

void operator delete( void *ptr ){
    // printf("From delete: pointer %p is delete\n",ptr);
    MemoryInfo* tem=rfind(ptr);
    printFreeLog(tem);
    free(tem->pointer);
    deleteMemoryInfo(tem);
}

void operator delete[]( void *ptr ){
    // printf("From delete[]: pointer %p is delete\n",ptr);
    MemoryInfo* tem=rfind(ptr);
    printFreeLog(tem);
    deleteMemoryInfo(tem);
    free(ptr);
}

void DEfree(void *ptr){
    // printf("From free: pointer %p is delete\n",ptr);
    MemoryInfo* tem=rfind(ptr);
    printFreeLog(tem);
    deleteMemoryInfo(tem);
    free(ptr);
}

void addMemoryInfo(MemoryInfo* a,MemoryInfo* b,MemoryInfo*c){
    if(c){
        a->next=b;
        b->next=c;
        c->before=b;
        b->before=a;
    }
    else{
        a->next=b;
        b->before=a;
    }
}

void deleteMemoryInfo(MemoryInfo* a){
    if(a->next){
        a->before->next=a->next;
        a->next->before=a->before;
    }
    else{
        a->before->next=a->next;
    }
    free(a);
}

void allocate(void* m,size_t size){
    MemoryInfo* change = (MemoryInfo*) malloc(sizeof(MemoryInfo));
    change->pointer=m;
    change->size=size;
    MemoryInfo* tem = beginNode;
    while(tem->next){
        if(tem->next->size<size){break;}
        tem=tem->next;
    }
    addMemoryInfo(tem,change,tem->next);
}

MemoryInfo* find(void*ptr){
    MemoryInfo* tem = beginNode->next;
    while(tem){
        if(tem->pointer==ptr){break;}
        tem=tem->next;
    }
    return tem;
}

MemoryInfo* rfind(void*ptr){
    MemoryInfo* tem = beginNode->next;
    while(tem){
        if(tem->pointer<=ptr && tem->pointer+tem->size > ptr){break;}
        tem=tem->next;
    }
    return tem;
}

void printAllocLog(MemoryInfo* m){
    f<<"======================================================================"<<endl;
    f<<"type:         Memory Allocate"<<endl;
    f<<"pointer:"<<setw(20)<<m->pointer<<endl;
    f<<"Size:"<<setw(24)<<m->size<<endl;
    f<<"File:"<<setw(24)<<m->file<<endl;
    f<<"Line:"<<setw(24)<<m->line<<endl;
}

void printFreeLog(MemoryInfo* m){
    f<<"======================================================================"<<endl;
    f<<"type:                Memory Free"<<endl;
    f<<"pointer:"<<setw(20)<<m->pointer<<endl;
}

void printResult(){
    // if(!beginNode->next){
    //     fr<<"No memory leak"<<endl;
    // }
    if(beginNode->next){
        MemoryInfo* tem = beginNode;
        while(tem->next){
            tem=tem->next;
            if(tem->file){
                printOneResult(tem);
            }
        }
    }
}

void printOneResult(MemoryInfo* m){
    fr<<"======================================================================"<<endl;
    fr<<"pointer:"<<setw(20)<<m->pointer<<endl;
    fr<<"Size:"<<setw(24)<<m->size<<endl;
    fr<<"File:"<<setw(24)<<m->file<<endl;
    fr<<"Line:"<<setw(24)<<m->line<<endl;
}