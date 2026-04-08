#include "compression/LZMA.h"
#include <cstddef>
#include <cstdint>
#include <vector>


using namespace std;
void LZMACompression::compress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    fileManager.writeFile(outputFile, inputData);
}

void LZMACompression::decompress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);    
    fileManager.writeFile(outputFile, inputData);
}
