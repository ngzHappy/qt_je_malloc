#pragma once

#ifdef __cplusplus

#if      __has_include("../global/qglobal.h")
#include "../global/qglobal.h"
#endif

#include <memory>

#ifndef _Qt_SSTD_CORE_EXPORT
#define _Qt_SSTD_CORE_EXPORT Q_CORE_EXPORT
#endif

namespace sstd {
    namespace _private_qt {
        class _Qt_SSTD_CORE_EXPORT SSTDMemory {
        public:
            static constexpr inline void* operator new  (std::size_t, void* ptr) noexcept {
                return ptr;
            }
        public:
            static constexpr inline void* operator new[](std::size_t, void* ptr) noexcept {
                return ptr;
            }
        public:
            static constexpr inline void operator delete  (void *, void *) noexcept {
            }
        public:
            static constexpr inline void operator delete[](void *, void *) noexcept {
            }
        public:
            static void* operator new (std::size_t count);
            static void operator delete(void * ptr);
        public:
            static void* operator new[](std::size_t count);
            static void operator delete[](void * ptr);
        public:
            static void* operator new(std::size_t count, std::align_val_t al);
            static void operator delete(void* ptr, std::align_val_t al);
        public:
            static void* operator new[](std::size_t count, std::align_val_t al);
            static void operator delete[](void* ptr, std::align_val_t al);
        };
    }
}/*namespace sstd*/

#ifndef _q_t__SSTD_MEMORY_DEFINE
#define _q_t__SSTD_MEMORY_DEFINE \
public : \
static inline constexpr void* operator new  (std::size_t count, void* ptr) { return sstd::_private_qt::SSTDMemory::operator new(count,ptr); } \
static inline constexpr void* operator new[](std::size_t count, void* ptr) { return sstd::_private_qt::SSTDMemory::operator new[](count,ptr); } \
static constexpr inline void operator delete  (void * a, void * b) noexcept{ return sstd::_private_qt::SSTDMemory::operator delete(a,b); } \
static constexpr inline void operator delete[](void * a, void * b) noexcept { return sstd::_private_qt::SSTDMemory::operator delete[](a,b); } \
static inline void* operator new (std::size_t count) { return sstd::_private_qt::SSTDMemory::operator new(count); } \
static inline void operator delete(void * ptr) { return sstd::_private_qt::SSTDMemory::operator delete(ptr); } \
static inline void* operator new[](std::size_t count) { return sstd::_private_qt::SSTDMemory::operator new(count); } \
static inline void operator delete[](void * ptr) { return sstd::_private_qt::SSTDMemory::operator delete(ptr); } \
static inline void* operator new(std::size_t count, std::align_val_t al) { return sstd::_private_qt::SSTDMemory::operator new(count, al); } \
static inline void operator delete(void* ptr, std::align_val_t al) { return sstd::_private_qt::SSTDMemory::operator delete(ptr, al); } \
static inline void* operator new[](std::size_t count, std::align_val_t al) { return sstd::_private_qt::SSTDMemory::operator new(count, al); } \
static inline void operator delete[](void* ptr, std::align_val_t al) { return sstd::_private_qt::SSTDMemory::operator delete(ptr, al); }
#endif

Q_CORE_EXPORT void *qMalloc(size_t size);
Q_CORE_EXPORT void qFree(void *ptr);
Q_CORE_EXPORT void *qRealloc(void *ptr, size_t size);

#endif

/*Endl of hpp*/


