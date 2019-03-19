//
//  EntityPool.hpp
//  ECSKit
//
//  Created by 이현우 on 17/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#pragma once

#include "Common.h"
#include "Traits.hpp"

namespace ECSKit {
    class Entity;
    
    // Entity pool class.
    class EntityPool {
    private:
        
        // Unique identifier of pool object.
        static uint32_t _idCounter;
        const uint32_t _id = _idCounter++;
        
    public:
        
        EntityPool(EntityPoolMaxSize capacity = 0);
        ~EntityPool();
        
        FORCEINLINE uint32_t id() const;
        
        template<typename Comp, typename ...Params>
        void assign(Entity &entity, Params &&... params);
    };
}
