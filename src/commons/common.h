#ifndef ADCLASSIFIER2_COMMON_H
#define ADCLASSIFIER2_COMMON_H
#include <utility>
#include "NcbiTaxonomy.h"
#include <iostream>
#define kmerBufSize 1'000'000'000  // 1'000'000'000 //286'000'000 //   10'000'000'000 | 286'000'000 (16 byte x 1 giga = 16 GB)
// 10'000'000'000 -> build_dir 397G RAM
// 1'000'000'000 -> build_dir 39.7G RAM
#define SplitNum 4096
#define likely(x) __builtin_expect((x),1)
#define unlikely(x) __builtin_expect((x),0)

template<typename T>
struct Buffer {
    T *buffer;
    size_t startIndexOfReserve;
    size_t bufferSize;

    explicit Buffer(size_t sizeOfBuffer=100) {

        buffer = (T *) malloc(sizeof(T) * sizeOfBuffer);
        bufferSize = sizeOfBuffer;
        startIndexOfReserve = 0;
    };

    size_t reserveMemory(size_t numOfKmer) {
        size_t offsetToWrite = __sync_fetch_and_add(&startIndexOfReserve, numOfKmer);
        return offsetToWrite;
    };

    void reallocateMemory(size_t sizeOfBuffer) {
        if (sizeOfBuffer > bufferSize) {
            buffer = (T *) realloc(buffer, sizeof(T) * sizeOfBuffer);
            bufferSize = sizeOfBuffer;
        }
    };

    void add(T element) {
        buffer[startIndexOfReserve ++] = element;
    }

    // Destructor
    ~Buffer() {
        free(buffer);
    }
};

struct Sequence{
    Sequence(size_t start, size_t end, size_t length, size_t seqLength = 0)
            : start(start), end(end), length(length), seqLength(seqLength) {}
    Sequence() : start(0), end(0), length(0), seqLength(0) { }
    size_t start;
    size_t end;
    size_t length;
    size_t seqLength;
};

inline bool fileExist(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void process_mem_usage(double& vm_usage, double& resident_set);



#endif //ADCLASSIFIER2_COMMON_H
