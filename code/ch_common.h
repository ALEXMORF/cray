#pragma once

#define global_variable static
#define local_persist static
#define internal static

#include <math.h>
#include <float.h>
#include <stdint.h>
#include <stdio.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

typedef i32 b32;
typedef bool b8;

#define EPSILON 0.000001f
#define F32Max FLT_MAX
#define U32Max UINT_MAX
#define Pi32 3.1415926f

#define CH_ASSERT(X) do { if (!(X)) *(int *)0 = 0; } while (0)

//NOTE(chen): put your own assert here
#ifndef ASSERT
#define ASSERT(X) CH_ASSERT(X)
#endif 

#define KB(Value) (1024LL*(Value))
#define MB(Value) (1024LL*KB(Value))
#define GB(Value) (1024LL*MB(Value))