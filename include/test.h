#ifndef TEST_H
#define TEST_H
#include "file.h"
#include <string>


using namespace std;
class Compression {
public:
    virtual void compress(const string& inputFile, const string& outputFile) = 0;
    virtual void decompress(const string& inputFile, const string& outputFile) = 0;
    virtual ~Compression() = default;
};

class TestCompression : public Compression {
public:
    void compress(const string& inputFile, const string& outputFile) override;
    void decompress(const string& inputFile, const string& outputFile) override;

private:
    FileManager fileManager;
};

#endif