#include "standardRLE.h"



using namespace std;
void RLECompression::compress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    vector<uint8_t> outputData;
    for(int i = 0; i < inputData.size(); ++i) {
        uint8_t currentByte = inputData[i];
        uint8_t count = 1;
        while(i + 1 < inputData.size() && inputData[i + 1] == currentByte && count < 127) {
            ++count;
            ++i;
        }
        outputData.push_back(0b10000000 | count);
        outputData.push_back(currentByte);
    }
    fileManager.writeFile(outputFile, outputData);
}

void RLECompression::decompress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    vector<uint8_t> outputData;
    for(int i = 0; i < inputData.size(); i+=2) {
        uint8_t controlByte = inputData[i];
        uint8_t valueByte = inputData[i + 1];
        uint8_t count = controlByte & 0b01111111;
        for(int j = 0; j < count; ++j) {
            outputData.push_back(valueByte);
        }
    }
    fileManager.writeFile(outputFile, outputData);
}