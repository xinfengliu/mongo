#pragma once
#ifndef MONGO_PLATFORM_COMPILER_SUNCC_H
#define MONGO_PLATFORM_COMPILER_SUNCC_H
/**
 * Compiler-specific implementations for Sun CC.
 */

/**
 * Use this to decorate the declaration of functions that will not return.
 *
 * Correct:
 *    MONGO_COMPILER_NORETURN void myAbortFunction();
 */
#define MONGO_COMPILER_NORETURN __attribute__((__noreturn__))

/**
 * Use this to decorate unused variable declarations.
 */
#define MONGO_COMPILER_VARIABLE_UNUSED 

/**
 * Use this on a type declaration to specify its minimum alignment.
 *
 * Alignments should probably always be powers of two.  Also, note that most allocators will not be
 * able to guarantee better than 16- or 32-byte alignment.
 *
 * Correct:
 *    class MONGO_COMPILER_ALIGN_TYPE(16) MyClass {...};
 *
 * Incorrect:
 *    MONGO_COMPILER_ALIGN_TYPE(16) class MyClass {...};
 *    class MyClass{...} MONGO_COMPILER_ALIGN_TYPE(16);
 */
#define MONGO_COMPILER_ALIGN_TYPE(ALIGNMENT) __attribute__(( __aligned__(ALIGNMENT) ))

/**
 * Use this on a global variable or structure field declaration to specify that it must be allocated
 * at a location that is aligned to a multiple of "ALIGNMENT" bytes.
 *
 * Note that most allocators will not allow heap allocated alignments that are better than 16- or
 * 32-byte aligned.  Stack allocators may only guarantee up to the natural word length worth of
 * alignment.
 *
 * Correct:
 *    class MyClass {
 *        MONGO_COMPILER_ALIGN_VARIABLE(8) char a;
 *    };
 *
 *    MONGO_COMPILER_ALIGN_VARIABLE(8) class MyClass {...} singletonInstance;
 *
 * Incorrect:
 *    int MONGO_COMPILER_ALIGN_VARIABLE(16) a, b;
 */
#define MONGO_COMPILER_ALIGN_VARIABLE(ALIGNMENT) __attribute__(( __aligned__(ALIGNMENT) ))

#endif /* MONGO_PLATFORM_COMPILER_SUNCC_H */
