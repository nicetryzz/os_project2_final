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
        int* z;
        TestObj(){
            z=new int[2];
        }
        virtual ~TestObj(){};
};

int main(){ 
    f.open("history_class2.log",ios::out);
    fr.open("result_class2.log",ios::out);
    // case3: class数组数据类型增删
    TestObj* case3_0 = new TestObj;
    TestObj* case3_1 = new TestObj[2];
    TestObj* case3_2 = (TestObj*)malloc(sizeof(TestObj));
    TestObj* case3_3 = (TestObj*)calloc(10,sizeof(TestObj));
    TestObj* case3_4_1 = (TestObj*)malloc(sizeof(TestObj));
    TestObj* case3_4_2 = (TestObj*)realloc(case3_4_1,2*sizeof(TestObj));
    delete case3_0;
    delete[] case3_1;
    free(case3_2);
    free(case3_3);
    free(case3_4_2);
    printResult();
    f.close();
    fr.close();
}