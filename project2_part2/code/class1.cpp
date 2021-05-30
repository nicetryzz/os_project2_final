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

class TestObj{
    public:
        int z;
        TestObj(){
            z=0;
        }
        virtual ~TestObj(){};
};

int main(){ 
    f.open("history_class1.log",ios::out);
    fr.open("result_class1.log",ios::out);
    // case2: class基础数据类型增删
    TestObj* case2_0 = new TestObj;
    TestObj* case2_1 = new TestObj[2];
    TestObj* case2_2 = (TestObj*)malloc(sizeof(TestObj));
    TestObj* case2_3 = (TestObj*)calloc(10,sizeof(TestObj));
    TestObj* case2_4_1 = (TestObj*)malloc(sizeof(TestObj));
    TestObj* case2_4_2 = (TestObj*)realloc(case2_4_1,2*sizeof(TestObj));
    delete case2_0;
    delete[] case2_1;
    free(case2_2);
    free(case2_3);
    free(case2_4_2);
    printResult();
    f.close();
    fr.close();
}