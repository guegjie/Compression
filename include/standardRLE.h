#ifndef RLE_H
#define RLE_H
#include "compression.h"
#include "file.h"
#include <string>


using namespace std;
class RLECompression : public Compression {
public:
    void compress(const string& inputFile, const string& outputFile) override;
    void decompress(const string& inputFile, const string& outputFile) override;

private:
    FileManager fileManager;
};

#endif
