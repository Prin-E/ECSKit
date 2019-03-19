//
//  Entity.cpp
//  ECSKit
//
//  Created by 이현우 on 17/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#include "Entity.hpp"

using namespace ECSKit;

#pragma mark - Constructor / Destructor
Entity::Entity(uint32_t newVariation, uint32_t newIndex) {
    _variation = newVariation;
    _index = newIndex;
}

Entity::~Entity() {
}

#pragma mark - Properties
uint64_t Entity::identifier() const { return _identifier; }
uint32_t Entity::variation() const { return _variation; }
uint32_t Entity::index() const { return _index; }
