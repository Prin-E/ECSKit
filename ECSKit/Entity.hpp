//
//  Entity.hpp
//  ECSKit
//
//  Created by 이현우 on 17/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#pragma once

#include "Common.h"

namespace ECSKit {
    class EntityPool;
    
    // Entity class
    class Entity {
    // Variables
    private:
        using size_type = uint32_t;
        
        // Entity has 64-bit unsigned integer value.
        union {
            struct {
                size_type _variation;
                size_type _index;
            };
            uint64_t _identifier;
        };
        
    // Private Functions
    protected:
        
        // Constructor class only be called by pool class.
        friend class EntityPool;
        Entity(uint32_t newVariation, uint32_t newIndex);
        ~Entity();
        
    // Functions
    public:
        
        // Constructor and destructor
        Entity() = delete;
    };
}
