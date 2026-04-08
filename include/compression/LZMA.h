#ifndef LZMA_H
#define LZMA_H
#include "compression/compression.h"
#include "core/file.h"
#include <string>


class LZMACompression : public Compression {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
    void decompress(const std::string& inputFile, const std::string& outputFile) override;

private:
    FileManager fileManager;
};

#endif
