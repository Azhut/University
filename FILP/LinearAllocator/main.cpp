#include <iostream>
#include <map>
#include <Windows.h>
#include "LinearAllocator.h"

class CStringComparator {
public:
    bool operator()(const char *A, const char *B) const {
        while (true) {
            if (A[0] == B[0]) {
                //A = B
                if (!A[0])
                    return false;

                A++;
                B++;
            } else {
                return A[0] < B[0];
            }
        }
    }
};

void TextMapTest() {
    LinearAllocator<std::pair<const char*, size_t>> allocator(100);

    // Используем аллокатор для std::pair<const char*, size_t>
    std::map<const char*, size_t, CStringComparator, std::allocator<std::pair<const char*, size_t>>> Map;

    const char* Words[] = { "Who", "Are", "You", "Who" };

    for (size_t i = 0; i < sizeof(Words) / sizeof(Words[0]); i++) {
        auto It = Map.find(Words[i]);
        if (It == Map.end()) {
            Map.insert(std::make_pair(Words[i], 1));
        } else {
            It->second++;
        }
    }

    for (auto Entry : Map) {
        std::cout << "Word " << Entry.first << ", count " << Entry.second << std::endl;
    }
}

ULONGLONG GetCurrentTimeMs() {
    SYSTEMTIME S = { 0 };
    GetSystemTime(&S);
    FILETIME F = { 0 };
    SystemTimeToFileTime(&S, &F);
    ULARGE_INTEGER Int;
    Int.LowPart = F.dwLowDateTime;
    Int.HighPart = F.dwHighDateTime;
    return Int.QuadPart / 10000;
}

int main() {
    LinearAllocator<void> allocator(100);

    void *ptr1 = allocator.allocate(20);
    void *ptr2 = allocator.allocate(50);
    allocator.deallocate();
    void *ptr3 = allocator.allocate(80);

    ULONGLONG Start = GetCurrentTimeMs();
    TextMapTest();
    ULONGLONG End = GetCurrentTimeMs();

    std::cout << "Time (ms) " << (int) (End - Start) << std::endl;

    system("pause"); // Pause the console before exiting

    return 0;
}
