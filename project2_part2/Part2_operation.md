## Part 2

​	In this part, we give several example in the folder, thus as `base.cpp`, `class1.cpp`, `class2.cpp` and `leak.cpp`.

​	You can run it after compile.

​	The output of memory detection is in `history_*.log` file, the memory leak is in `result_*.log`.

​	If you want to test it in your code, you need to include `MemRecord.cpp` define the method at top, like this:

```c++
#define new DEBUG_NEW
#define malloc(size) DEBUG_MALLOC(size)
#define calloc(num,size) DEBUG_CALLOC(num,size)
#define realloc(ptr,size) DEBUG_REALLOC(ptr,size)
#define delete DEBUG_DELETE
#define free(pointer) DEBUG_FREE(pointer)
```

​	Also you need to open `fstream` `f` and `fr` to the `history.log` and `result.log` that you want.

​	Call the `printResult` method, and close `f` and `fr` at last.

```c++
    f.open("history_base.log",ios::out);
    fr.open("result_base.log",ios::out);
    // your code
	printResult();
    f.close();
    fr.close();
```

