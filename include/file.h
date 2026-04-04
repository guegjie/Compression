#ifndef FILE_H
#define FILE_H
#include <vector>
#include <cstdint>
#include <string>


using namespace std;
class FileManager {
public:
    vector<uint8_t> readFile(const string& filePath) const;
    void writeFile(const string& filePath, const vector<uint8_t>& contents) const;
};

#endif