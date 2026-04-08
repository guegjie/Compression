#include "packBitRLE.h"



using namespace std;
void RLEPCompression::compress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    vector<uint8_t> outputData;
    for (int i = 0; i < inputData.size();) {
        int j = i;
        while (j + 1 < inputData.size() && inputData[j + 1] == inputData[i] && (j - i + 1) < 128) {
            ++j;
        }

        int count = j - i + 1;

        if(count > 1) {
            int8_t controlByte = 1 - count;
            outputData.push_back(controlByte);
            outputData.push_back(inputData[i]);
            i = j + 1;
        } else {
            j = i;
            while(j + 1 < inputData.size() && (j - i) < 127) {
                if (j + 2 < inputData.size() && inputData[j + 1] == inputData[j + 2]) break;
                ++j;
            }
            int actualCount = j - i + 1;
            int8_t controlByte = actualCount - 1;
            outputData.push_back(controlByte);
            for(int k = i; k <= j; ++k) {
                outputData.push_back(inputData[k]);
            }
            i = j + 1;
        }
    }
    fileManager.writeFile(outputFile, outputData);
}

void RLEPCompression::decompress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    vector<uint8_t> outputData;
    int i = 0;
    while (i < inputData.size()) {
        int8_t controlByte = (uint8_t)inputData[i];
        if (controlByte & 0b10000000){
            int count = controlByte & 0b01111111;
            uint8_t valueByte = inputData[i++];
            for(int j = 0; j < count; ++j) {
                outputData.push_back(valueByte);
            }
        } else {
            int count = controlByte & 0b01111111;
            for(int j = 0; j<count; ++j) {
                outputData.push_back(inputData[i++]);
            }
        }
    }
    fileManager.writeFile(outputFile, outputData);
}
