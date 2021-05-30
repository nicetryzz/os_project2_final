#include <stdio.h>
#include<stdlib.h>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

#define DEBUG_NEW MemAllocate(__FILE__,__LINE__)*new
#define DEBUG_MALLOC(size) (MemAllocate(__FILE__,__LINE__)*Demalloc(size))
#define DEBUG_CALLOC(num,size) (MemAllocate(__FILE__,__LINE__)*Decalloc(num,size))
#define DEBUG_REALLOC(ptr,size) (MemAllocate(__FILE__,__LINE__)*Derealloc(ptr,size))
#define DEBUG_DELETE delete
#define DEBUG_FREE DEfree

struct MemoryInfo{
    void* pointer;
    size_t size;
    char const* file;
    int line;
    MemoryInfo* next;
    MemoryInfo* before;
};

class MemAllocate{
    private:
        char const* file;
        int line;
    public:
        MemAllocate(char const* _file,int _line);
        template <class T> inline T* operator*(T* p);
};

void* operator new(size_t  size);

void* operator new[](size_t  size);

void* Demalloc(size_t size);

void* Decalloc(size_t num,size_t size);

void* Derealloc(void* ptr, size_t size);

void operator delete( void *ptr );

void operator delete( void *ptr );

void DEfree(void *ptr);

void addMemoryInfo(MemoryInfo* a,MemoryInfo* b,MemoryInfo*c);

void deleteMemoryInfo(MemoryInfo* a);

void allocate(void* m,size_t size);

MemoryInfo* find(void*ptr);

MemoryInfo* rfind(void*ptr);

void printAllocLog(MemoryInfo* m);

void printFreeLog(MemoryInfo* m);

void printResult();

void printOneResult(MemoryInfo* m);