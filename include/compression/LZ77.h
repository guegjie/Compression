#ifndef LZ77_H
#define LZ77_H
#include "compression/compression.h"
#include "core/file.h"
#include <string>


class LZ77Compression : public Compression {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
    void decompress(const std::string& inputFile, const std::string& outputFile) override;

private:
    FileManager fileManager;
};

#endif