#include "compression/test.h"



using namespace std;
void TestCompression::compress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    fileManager.writeFile(outputFile, inputData);
}

void TestCompression::decompress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    fileManager.writeFile(outputFile, inputData);
}