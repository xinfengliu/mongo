// basic.h

#pragma once
#ifndef MONGO_PLATFORM_BASIC_H
#define MONGO_PLATFORM_BASIC_H

#ifdef _WIN32
#include "windows_basic.h"
#endif

#if defined(__linux__)

#include <cstring>

// glibc's optimized versions are better than g++ builtins
# define __builtin_strcmp strcmp
# define __builtin_strlen strlen
# define __builtin_memchr memchr
# define __builtin_memcmp memcmp
# define __builtin_memcpy memcpy
# define __builtin_memset memset
# define __builtin_memmove memmove
#endif


#endif /* MONGO_PLATFORM_BASIC_H */
