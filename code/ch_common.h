#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static
#define local_persist static
#define internal static

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

inline f32
CalcSecondsPassed(clock_t BeginClock)
{
    return (f32)(clock() - BeginClock) / (f32)CLOCKS_PER_SEC;
}

#define EPSILON 0.000001f
#define F32Max FLT_MAX
#define U32Max UINT_MAX
#define Pi32 3.1415926f

#define CH_ASSERT(X) do { if (!(X)) *(int *)0 = 0; } while (0)

//NOTE(chen): put your own assert here
#ifndef ASSERT
#define ASSERT(X) CH_ASSERT(X)
#endif 

#define KB(Value) (1024LL*((u64)Value))
#define MB(Value) KB(1024LL*(u64)Value)
#define GB(Value) MB(1024LL*(u64)Value)

#define ARRAY_COUNT(Array) (sizeof(Array)/sizeof((Array)[0]))

inline u32 
BITS(int Count) {
    ASSERT(Count <= 31);
    return (1ul << Count) - 1;
}

typedef void panic(char *Message);
global_variable panic *__PanicStr;

internal void
Panic(char *Fmt, ...)
{
    va_list Args;
    va_start(Args, Fmt);
    
    char PanicBuffer[1024];
    vsnprintf(PanicBuffer, sizeof(PanicBuffer), Fmt, Args);
    __PanicStr(PanicBuffer);
    
    va_end(Args);
}
