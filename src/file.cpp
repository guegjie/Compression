#include "file.h"
#include <fstream>
#include <sstream>
#include <stdexcept>


using namespace std;
vector<uint8_t> FileManager::readFile(const string& filePath) const {
    ifstream inFile(filePath, ios::binary);
    if (!inFile.is_open()) {
        throw runtime_error("File already open: " + filePath);
    }

    inFile.seekg(0, ios::end);
    streamsize size = inFile.tellg();

    vector<uint8_t> buffer(size);
    inFile.seekg(0, ios::beg);
    if (size > 0) {
        inFile.read(reinterpret_cast<char*>(buffer.data()), size);
    }
    inFile.close();
    return buffer;
}


void FileManager::writeFile(const string& filePath, const vector<uint8_t>& contents) const {
    ofstream outFile(filePath, ios::binary);
    if (!outFile.is_open()) {
        throw runtime_error("File already open: " + filePath);
    }
    outFile.write(reinterpret_cast<const char*>(contents.data()), contents.size());
    outFile.close();
    return;
}

