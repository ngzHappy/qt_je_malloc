#include <stdlib.h>

#ifdef  _DEBUG
#pragma comment(lib,"D:/usr/local/ssl/lib/jemallocd.lib") 
#else
#pragma comment(lib,"D:/usr/local/ssl/lib/jemalloc.lib") 
#endif

__declspec(dllimport) void * je_malloc(size_t size);
__declspec(dllimport) void   je_free(void *ptr);
__declspec(dllimport) void * je_aligned_alloc(size_t alignment, size_t size);
__declspec(dllimport) void * je_realloc(void *ptr, size_t size);

__declspec(dllexport) void * auto_malloc(size_t size) {
    return je_malloc(size);
}

__declspec(dllexport) void   auto_free(void *ptr) {
    je_free(ptr);
}

__declspec(dllexport) void * auto_aligned_alloc(size_t alignment, size_t size) {
    return je_aligned_alloc(alignment, size);
}

__declspec(dllexport) void * auto_realloc(void *ptr, size_t size) {
    return je_realloc(ptr, size);
}


