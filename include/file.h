#ifndef FILE_H
#define FILE_H
#include <vector>
#include <cstdint>
#include <string>


class FileManager {
public:
    std::vector<uint8_t> readFile(const std::string& filePath) const;
    void writeFile(const std::string& filePath, const std::vector<uint8_t>& contents) const;
};

#endif