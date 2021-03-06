// bits.h

/*    Copyright 2012 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once
#ifndef MONGO_PLATFORM_BITS_H
#define MONGO_PLATFORM_BITS_H

// figure out if we're on a 64 or 32 bit system

#if defined(__x86_64__) || defined(__amd64__) || defined(_WIN64) || defined(__LP64__)
#define MONGO_PLATFORM_64
#elif defined(__i386__) || defined(_WIN32)
#define MONGO_PLATFORM_32
#else
#error "unknown platform"
#endif


#endif /* MONGO_PLATFORM_BITS_H */
