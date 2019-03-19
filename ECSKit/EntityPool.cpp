//
//  EntityPool.cpp
//  ECSKit
//
//  Created by 이현우 on 17/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#include "EntityPool.hpp"
#include <cassert>

using namespace ECSKit;

uint32_t EntityPool::_idCounter = 0;

EntityPool::EntityPool(EntityPoolMaxSize capacity) {
    assert(_idCounter == UINT32_MAX);
    
    
}

uint32_t EntityPool::id() const { return _id; }
