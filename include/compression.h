#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <string>

using namespace std;

class Compression {
public:
    virtual void compress(const string& inputFile, const string& outputFile) = 0;
    virtual void decompress(const string& inputFile, const string& outputFile) = 0;
    virtual ~Compression() = default;
};

#endif
