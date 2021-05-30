# Implementatiom

## Detect memory allocation and release in a process

### Before work

​	In order to detect the memory allocation and release, we need to know the basic ways of memory allocation and release.

​	For memory allocation there are 5 types:

* `new`
* `new[]`
* `malloc`

* `calloc`

* `realloc`

​    And only 3 types for memory free:

* `delete`
* `delete[]`
* `free`

​    Thus we only need to overwrite those 8 functions to detect memory allocation and release.

### Data structure

​	As before work analysis, we need to record  the informations when those 8 methods  runs.

​	We plans to output one .log document to record both informations of  allocation and free.

​	Also, we choose a double linked list to record the pointer that still not free.

​	For each node, we record the 4 kinds of informations:

* pointer
* size
* file name
* file line

​    And it is packaging in to the structure `MemoryInfo`.

```c++
struct MemoryInfo{
    void* pointer;
    size_t size;
    char const* file;
    int line;
    MemoryInfo* next;
    MemoryInfo* before;
};v
```

### Memory allocation

​	When memory allocation occurs, we need to record the informations of it .

​    All of the 5 methods get the informations about size and return the pointer.

​	Thus we can recording the pointer and size over write method.

​	For file name and file line, I create a new class `MemAllocate` to pass them.

```c++
class MemAllocate{
    private:
        char const* file;
        int line;
    public:
        MemAllocate(char const* _file,int _line);
        template <class T> inline T* operator*(T* p);
};
```

​	During operator`*` of `MemAllocate`, it find the suitable node and store the file and size information in it.

### Memory free

​	During the return of memory free are all void, also it is no need to record the file and line, we only need  to over write and print the message to .log document.

### Test case

​	For those 8 methods, we need to test for the basic data type, class without new and class with new.

​	It is correct for basic data type, but wrong for class when use the `new` and `new[]`.

​	After we check it for several times, we find that the pointer allocations returned is 8 bigger than the pointer returns by `malloc` in it,thus we can't match it correctly.

​	Instead we check in pointer is weather in the range of the node(pointer~pointer+size).

### Memory leak

​	For memory leak, it only need to delete the node when memory free.

​	And at the end of process, print the rest node in double linked list to check the memory leak.

# Future direction
   Cause the memory allocation and free is only for data segement, we can try to detect rest segements like heap, stack and code.
# Summary
# Division of labor
 

