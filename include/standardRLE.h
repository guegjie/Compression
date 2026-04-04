#ifndef STANDARD_RLE_H
#define STANDARD_RLE_H
#include "compression.h"
#include "file.h"
#include <string>


class RLECompression : public Compression {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
    void decompress(const std::string& inputFile, const std::string& outputFile) override;

private:
    FileManager fileManager;
};

#endif
