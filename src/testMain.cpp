#include <cassert>
#include <filesystem>
#include <iostream>
#include <vector>
#include "file.h"
#include "compression.h"
#include "test.h"
#include "standardRLE.h"
#include "packBitRLE.h"

using namespace std;
void compressDecompress(Compression& comp, const string& name, const vector<uint8_t>& input) {
    FileManager files;
    filesystem::create_directories("testTmp");

    const string in  = "testTmp/" + name + "_in.bin";
    const string cmp = "testTmp/" + name + "_cmp.bin";
    const string out = "testTmp/" + name + "_out.bin";

    files.writeFile(in, input);
    comp.compress(in, cmp);
    comp.decompress(cmp, out);

    const vector<uint8_t> restored = files.readFile(out);
    assert(restored == input);
}

int main() {
    TestCompression test;
    RLECompression rle;
    RLEPCompression pack;

    compressDecompress(rle, "rleEmpty", {});
    compressDecompress(rle, "rleBasic", {'A','A','A','B','B','C'});
    compressDecompress(rle, "rleLongRun", std::vector<uint8_t>(200, 'A'));

    compressDecompress(pack, "packEmpty", {});
    compressDecompress(pack, "packMixed", {'A','B','C','D','D','D','E','F'});
    compressDecompress(pack, "packBinary", {0x00, 0x00, 0xFF, 0x10, 0x10, 0x10});

    std::cout << "All tests passed\n";
}