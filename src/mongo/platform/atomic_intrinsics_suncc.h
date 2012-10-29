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

/**
 * Implementation of the AtomicIntrinsics<T>::* operations for IA-32 and AMD64 systems using a
 * GCC-compatible compiler toolchain.
 */

#pragma once
#ifndef MONGO_PLATFORM_ATOMIC_INTRINSICS_SUNCC_H
#define MONGO_PLATFORM_ATOMIC_INTRINSICS_SUNCC_H

#if !defined(_LP64) && !defined(__LP64__)
#error "atomic_intrinsics_suncc.h currently only supports 64-bit build"
#endif 

//#include <boost/utility.hpp>
#include <atomic.h>
#include <mbarrier.h>

namespace mongo {

    //template <typename T, typename IsTLarge=void>
    template <typename T>
    class AtomicIntrinsics {
    public:

	//for 64-bit here, if other size data, then template specialization 
        static T compareAndSwap(volatile T* dest, T expected, T newValue) {
            return (T) atomic_cas_ptr(dest, (void *) expected, (void *) newValue);
        }

        static T swap(volatile T* dest, T newValue) {
	    return (T)atomic_swap_ptr(dest, (void *)newValue);
        }

        static T load(volatile const T* value) {
	    T result = *value;
	    __machine_acq_barrier(); //probablly not needed for sparc
            return result;
        }

        static void store(volatile T* dest, T newValue) {
            *dest = newValue;
	    __machine_rw_barrier(); //maybe only need #StoreLoad on sparc
	    //__machine_rel_barrier();
        }

        //static T fetchAndAdd(volatile T* dest, T increment); 
        static T fetchAndAdd(volatile T* dest, T increment) {
	    T old = *dest;
	    atomic_add_ptr(dest, (ssize_t) increment);
            return old;
        }

    private:
        AtomicIntrinsics();
        ~AtomicIntrinsics();
    };

    template <>  inline unsigned
    AtomicIntrinsics<unsigned>::fetchAndAdd(volatile unsigned* dest, 
					unsigned increment) {
     	unsigned old = *dest;
	atomic_add_32(dest, (int)increment); 
	return old;
    }

    template <> inline  int
    AtomicIntrinsics<int>::fetchAndAdd(volatile int* dest, 
					int increment) {
     	int old = *dest;
	atomic_add_32((volatile unsigned*)dest, increment);
	return old;
    }

    template <> inline unsigned
    AtomicIntrinsics<unsigned>::swap(volatile unsigned* dest, unsigned newValue) {
	    return atomic_swap_32(dest, newValue);
    }

    template <> inline int
    AtomicIntrinsics<int>::swap(volatile int* dest, int newValue) {
	    return atomic_swap_32((volatile unsigned*)dest, newValue);
    }

    template <> inline unsigned
    AtomicIntrinsics<unsigned>::compareAndSwap(volatile unsigned* dest, 
			unsigned expected, unsigned newValue) {
            return atomic_cas_32(dest, expected, newValue);
    }

    template <> inline int
    AtomicIntrinsics<int>::compareAndSwap(volatile int* dest, 
			int expected, int newValue) {
            return atomic_cas_32((volatile unsigned*)dest, expected, newValue);
    }

}  // namespace mongo

#endif /* MONGO_PLATFORM_ATOMIC_INTRINSICS_SUNCC_H */
