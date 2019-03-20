//
//  Allocator.hpp
//  ECSKit
//
//  Created by 이현우 on 20/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#pragma once

#include "Common.h"
#include <vector>

namespace ECSKit {
    using namespace std;
    
    class Allocator {
    public:
        
        static FORCEINLINE size_t getTotalAllocatedSize();
        static FORCEINLINE size_t getTotalUsedSize();
        
        static void* allocate(size_t length, size_t alignment = sizeof(size_t));
        
        template<typename T>
        static T* allocate(size_t length);
        
        static void deallocate(void* ptr);
    };
}
