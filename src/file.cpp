#include "file.h"
#include <fstream>
#include <sstream>
#include <stdexcept>


using namespace std;
string FileManager::readFile(const string& filePath) const {
    ifstream inFile;
    inFile.open(filePath);
    if (!inFile.is_open()) {
        throw runtime_error("File already open: " + filePath);
    }

    stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}


void FileManager::writeFile(const string& filePath, const string& contents) const {
    ofstream outFile;
    outFile.open(filePath);
    if (!outFile.is_open()) {
        throw runtime_error("File already open: " + filePath);
    }
    outFile << contents;
    outFile.close();
    return;
}


