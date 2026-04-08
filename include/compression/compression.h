#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <string>


class Compression {
public:
    virtual void compress(const std::string& inputFile, const std::string& outputFile) = 0;
    virtual void decompress(const std::string& inputFile, const std::string& outputFile) = 0;
    virtual ~Compression() = default;
};

#endif
