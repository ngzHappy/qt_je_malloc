#include "qt_sstd_memory.hpp"

#ifdef  _DEBUG
#pragma comment(lib,"D:/usr/local/ssl/lib/jemallocd.lib") 
#else
#pragma comment(lib,"D:/usr/local/ssl/lib/jemalloc.lib") 
#endif

extern "C" {
    __declspec(dllimport) void * je_malloc(size_t size);
    __declspec(dllimport) void   je_free(void *ptr);
    __declspec(dllimport) void * je_aligned_alloc(size_t alignment, size_t size);
}

namespace sstd {
    namespace _private_qt {
        void* SSTDMemory::operator new (std::size_t count) {
            return ::je_malloc(count);
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void SSTDMemory::operator delete(void * ptr) {
            return ::je_free(ptr);
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void* SSTDMemory::operator new[](std::size_t count) {
            return ::je_malloc(count);
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void SSTDMemory::operator delete[](void * ptr) {
            return ::je_free(ptr);
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void* SSTDMemory::operator new(std::size_t count, std::align_val_t al) {
            return ::je_aligned_alloc(static_cast<std::size_t>(al), count);
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void SSTDMemory::operator delete(void* ptr, std::align_val_t al) {
            return ::je_free(ptr); (void)al;
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void* SSTDMemory::operator new[](std::size_t count, std::align_val_t al) {
            return ::je_aligned_alloc(static_cast<std::size_t>(al), count);
        }
    }
}

namespace sstd {
    namespace _private_qt {
        void SSTDMemory::operator delete[](void* ptr, std::align_val_t al) {
            return ::je_free(ptr); (void)al;
        }
    }
}
