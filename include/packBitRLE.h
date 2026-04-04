#ifndef PACK_BIT_RLE_H
#define PACK_BIT_RLE_H
#include "compression.h"
#include "file.h"
#include <string>


class RLEPCompression : public Compression {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
    void decompress(const std::string& inputFile, const std::string& outputFile) override;

private:
    FileManager fileManager;
};

#endif
