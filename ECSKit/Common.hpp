//
//  Common.h
//  ECSKit
//
//  Created by 이현우 on 17/03/2019.
//  Copyright © 2019 Hyeonwoo Lee. All rights reserved.
//

#pragma once

#include <cstdint>
#include <cassert>

// inline definition
#if __clang__ || __GNUC__
#define FORCEINLINE __attribute__((always_inline))
#elif _MSC_VER
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE inline
#endif

// ignore warning of pragma mark in VS
#if _MSC_VER
#pragma warning (disable:4068)
#endif

