#include "LinearAllocator.h"

template <typename T>
LinearAllocator<T>::LinearAllocator(size_t size) : size(size), offset(0) {
    base_pointer = malloc(size * sizeof(T));
    if (base_pointer == nullptr) {
        throw std::bad_alloc();
    }
}

template <typename T>
LinearAllocator<T>::~LinearAllocator() {
    free(base_pointer);
}

template <typename T>
T* LinearAllocator<T>::allocate(size_t count) {
    if (count == 0) {
        printZeroSizeError();
        return nullptr;
    }

    size_t bytes = count * sizeof(T);

    void *aligned_ptr = alignPtr(static_cast<char *>(base_pointer) + offset, alignof(T));
    size_t aligned_offset = static_cast<char *>(aligned_ptr) - static_cast<char *>(base_pointer);

    if (aligned_offset + bytes > size * sizeof(T)) {
        printOverflowError();
        return nullptr;
    }

    T* ptr = reinterpret_cast<T*>(aligned_ptr);
    offset = aligned_offset + bytes;
    printSuccessMessage(ptr);
    return ptr;
}

template <typename T>
void LinearAllocator<T>::deallocate() {
    offset = 0;
}

template <typename T>
void* LinearAllocator<T>::printOverflowError() {
    std::cout << "Failed to allocate memory\n"
                 "Size of allocator is less than you need";
    return nullptr;
}

template <typename T>
void* LinearAllocator<T>::printZeroSizeError() {
    std::cout << "Failed to allocate memory\n"
                 "You can't allocate 0 bytes of memory";
    return nullptr;
}

template <typename T>
void* LinearAllocator<T>::printSuccessMessage(T* ptr) {
    std::cout << "Memory allocated at address: " << ptr << std::endl;
    return nullptr;
}

template <typename T>
void* LinearAllocator<T>::alignPtr(void* ptr, size_t alignment) {
    uintptr_t raw_address = reinterpret_cast<uintptr_t>(ptr);
    size_t misalignment = raw_address % alignment;
    size_t offset = misalignment != 0 ? (alignment - misalignment) : 0;
    return reinterpret_cast<void*>(raw_address + offset);
}
