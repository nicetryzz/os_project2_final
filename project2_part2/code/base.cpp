#include <stdio.h>
#include<stdlib.h>
#include <cstring>
using namespace std;

#include "MemRecord.cpp"

#define new DEBUG_NEW
#define malloc(size) DEBUG_MALLOC(size)
#define calloc(num,size) DEBUG_CALLOC(num,size)
#define realloc(ptr,size) DEBUG_REALLOC(ptr,size)
#define delete DEBUG_DELETE
#define free(pointer) DEBUG_FREE(pointer)

int main(){ 
    f.open("history_base.log",ios::out);
    fr.open("result_base.log",ios::out);
    // case1: 基础数据类型增删
    int* case1_0 = new int;
    int* case1_1 = new int[2];
    int* case1_2 = (int*)malloc(sizeof(int));
    int* case1_3 = (int*)calloc(10,sizeof(int));
    int* case1_4_1 = (int*)malloc(sizeof(int));
    int* case1_4_2 = (int*)realloc(case1_4_1,2*sizeof(int));
    delete case1_0;
    delete[] case1_1;
    free(case1_2);
    free(case1_3);
    free(case1_4_2);
    printResult();
    f.close();
    fr.close();
}