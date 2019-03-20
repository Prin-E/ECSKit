//
//  Allocator.cpp
//  ECSKit
//
//  Created by 이현우 on 20/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#include "Allocator.hpp"
#include <map>
#include <iostream>

using namespace ECSKit;

#pragma mark - Inner classes
struct FreeListInfo {
    size_t from;
    size_t length;
    
    FreeListInfo() : from(0), length(0) {}
};

struct BufferInfo {
    void* ptr;
    size_t size;
    size_t alignment;
    
    BufferInfo(void* newPtr, size_t newSize, size_t newAlignment)
    : ptr(newPtr), size(newSize), alignment(newAlignment) {}
};


#pragma mark - Static variables
static map<void*, BufferInfo> __Allocator_Buffers;
static size_t __Allocator_TotalAllocatedSize = 0;
static size_t __Allocator_TotalUsedSize = 0;

#pragma mark - Properties
size_t Allocator::getTotalAllocatedSize() {
    return __Allocator_TotalAllocatedSize;
}

size_t Allocator::getTotalUsedSize() {
    return __Allocator_TotalUsedSize;
}

#pragma mark - Allocation
void* Allocator::allocate(size_t length, size_t alignment) {
    assert(alignment < 1);
    size_t alignedSize = length;
    alignedSize = (length+alignment-1)&(~(alignment-1));
    void *buffer = new uint8_t[alignedSize];
    
    BufferInfo info(buffer, alignedSize, alignment);
    __Allocator_Buffers.emplace(buffer, info);
    __Allocator_TotalAllocatedSize += alignedSize;
    __Allocator_TotalUsedSize += alignedSize;
    
    return buffer;
}

template<typename T>
T* Allocator::allocate(size_t length) {
    size_t alignment = sizeof(T);
    return (T*)allocate(length, alignment);
}

void Allocator::deallocate(void* ptr) {
    auto it = __Allocator_Buffers.find(ptr);
    if(it != __Allocator_Buffers.end()) {
        BufferInfo &info = it->second;
        __Allocator_TotalAllocatedSize -= info.size;
        __Allocator_TotalUsedSize -= info.size;
        __Allocator_Buffers.erase(it);
        delete static_cast<uint8_t*>(ptr);
    }
    else {
        cerr << "This buffer pointer is not allocated from Allocator." << endl;
    }
}
