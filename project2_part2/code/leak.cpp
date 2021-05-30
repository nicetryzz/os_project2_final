#include <stdio.h>
#include<stdlib.h>
#include <cstring>
using namespace std;

// #include "MemRecord.h"
#include "MemRecord.cpp"

// #if defined( MEM_DEBUG )
#define new DEBUG_NEW
#define malloc(size) DEBUG_MALLOC(size)
#define calloc(num,size) DEBUG_CALLOC(num,size)
#define realloc(ptr,size) DEBUG_REALLOC(ptr,size)
#define delete DEBUG_DELETE
#define free(pointer) DEBUG_FREE(pointer)
// #endif

int main(){ 
    f.open("history_leak.log",ios::out);
    fr.open("result_leak.log",ios::out);
    // case4: leak
    int* case4_0 = new int;
    int* case4_1 = new int[2];
    int* case4_2 = (int*)malloc(sizeof(int));
    int* case4_3 = (int*)calloc(10,sizeof(int));
    int* case4_4_1 = (int*)malloc(sizeof(int));
    int* case4_4_2 = (int*)realloc(case4_4_1,2*sizeof(int));
    printResult();
    f.close();
    fr.close();
}