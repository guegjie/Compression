#include "LZMA.h"
#include <cstddef>
#include <cstdint>
#include <vector>


using namespace std;
struct LZPointer{
    uint8_t offset;
    uint8_t length;
};

LZPointer findLongestMatch(const vector<uint8_t>& data, size_t pos) {
    LZPointer bestMatch = {0, 0};
    for (size_t offset = 1; offset <= 255 && pos >= offset; ++offset) {
        size_t length = 0;
        while (length < 255 && pos + length < data.size() && data[pos - offset + length] == data[pos + length]) {
            ++length;
        }
        if (length > bestMatch.length) {
            bestMatch = LZPointer{(uint8_t)offset, (uint8_t)length};
        }
    }
    if (bestMatch.length < 3) {
        return {0, 0};
    }   
    return bestMatch;
}


void LZMACompression::compress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    vector<uint8_t> outputData;
    size_t i = 0;

    while (i < inputData.size()) {
        LZPointer match = findLongestMatch(inputData, i);
        if (match.length >= 3) {
            outputData.push_back(1);
            outputData.push_back(match.offset);
            outputData.push_back(match.length);
            i += match.length;
        } else {
            outputData.push_back(0);
            outputData.push_back(inputData[i]);
            i += 1;
        }
    }

    fileManager.writeFile(outputFile, outputData);
}

void LZMACompression::decompress(const string& inputFile, const string& outputFile) {
    vector<uint8_t> inputData = fileManager.readFile(inputFile);
    vector<uint8_t> outputData;
    size_t i = 0;

    while (i < inputData.size()) {
        uint8_t flag = inputData[i++];
        if (flag == 0) {
            outputData.push_back(inputData[i++]);
        } else {
            uint8_t offset = inputData[i++];
            uint8_t length = inputData[i++];
            size_t start = outputData.size() - offset;
            for (size_t j = 0; j < length; j++) {
                outputData.push_back(outputData[start + j]);
            }
        }
    }
    
    fileManager.writeFile(outputFile, outputData);
}
