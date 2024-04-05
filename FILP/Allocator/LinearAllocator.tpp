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
    // Реализация методов allocate, deallocate и прочих
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

