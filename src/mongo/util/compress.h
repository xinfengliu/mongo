// @file compress.h

#pragma once
#ifndef MONGO_UTIL_COMPRESS_H
#define MONGO_UTIL_COMPRESS_H

#include <string>

namespace mongo { 

    size_t compress(const char* input, size_t input_length, std::string* output);

    bool uncompress(const char* compressed, size_t compressed_length, std::string* uncompressed);

    size_t maxCompressedLength(size_t source_len);
    void rawCompress(const char* input,
        size_t input_length,
        char* compressed,
        size_t* compressed_length);

}



#endif /* MONGO_UTIL_COMPRESS_H */
