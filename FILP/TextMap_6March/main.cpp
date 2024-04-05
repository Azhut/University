// TextMap.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>
#include <map>
#include <cstdint>

using namespace std;

class CStringComparator
{
public:

    /*
        A < B --> true
    */
    bool operator()(const char* A, const char* B) const
    {
        while (true)
        {
            if (A[0] == B[0])
            {
                //A = B
                if (!A[0])
                    return false;

                A++;
                B++;
            }
            else
            {
                return A[0] < B[0];
            }
        }
    }
};

template <class T>
class CMyAllocator
{
public:
    typedef  T value_type;

    CMyAllocator()
    {

    }

    template <class U>
    CMyAllocator(const CMyAllocator<U> &V)
    {

    }

    T* allocate(size_t Count)
    {
        //printf("Allocate %d\n", (int)(Count * sizeof(T)));

        return (T*)malloc(sizeof(T) * Count);
    }

    void deallocate(T* V, size_t Count)
    {
        //printf("Free %d\n", (int)(Count * sizeof(T)));

        free(V);
    }
};

void TextMapTest()
{
    map<char*, size_t, CStringComparator, CMyAllocator<char*>> Map;

    char* Words[] = { "Who", "Are", "You", "Who" };
    char* Word;

    for (size_t i = 0; i < sizeof(Words) / sizeof(Words[0]); i++)
    {
        Word = Words[i];
        auto It = Map.find(Word);
        if (It == Map.end())
        {
            Map.insert(make_pair(Word, 1));
        }
        else
        {
            It->second++;
        }
    }

    for (auto Entry : Map)
    {
        std::cout << "Word " << Entry.first << ", count " << Entry.second << std::endl;
    }

}


