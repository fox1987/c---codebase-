#ifndef TYPES_H_
#define TYPES_H_
#include <stddef.h>
#include <stdint.h>
// 禁止拷贝和赋值的宏定义
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&); \
  void operator=(const TypeName&)

// 标明废弃的宏
#define DEPREATED __attribute__((deprecated))

// 申明一个函数指针
template <class T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];

#define arraysize(array)  (sizeof(ArraySizeHelper(array)))
#endif
