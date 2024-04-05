#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class LinearAllocator {
public:
    typedef T value_type;

    LinearAllocator(size_t size);
    ~LinearAllocator();
    T* allocate(size_t count);
    void deallocate();

private:
    size_t size;
    size_t offset;
    void* base_pointer;

    void* printOverflowError();
    void* printZeroSizeError();
    void* printSuccessMessage(T* ptr);
    void* alignPtr(void* ptr, size_t alignment);
};

#include "LinearAllocator.tpp" // Включаем реализацию методов шаблона
