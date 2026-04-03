#ifndef FILE_H
#define FILE_H
#include <string>


using namespace std;
class FileManager {
public:
    string readFile(const string& filePath) const;
    void writeFile(const string& filePath, const string& contents) const;
};

#endif