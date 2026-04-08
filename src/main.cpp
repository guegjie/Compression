#include <iostream>
#include <string>
#include <stdexcept>
#include "test.h"
#include "standardRLE.h"
#include "packBitRLE.h"
#include "LZMA.h"
#include "LZ77.h"



using namespace std;
Compression* createCompression(const string& type){
    if(type == "test") return new TestCompression();
    if(type == "rle") return new RLECompression();
    if(type == "rlep") return new RLEPCompression();
    if(type == "lz77") return new LZ77Compression();
    if(type == "lzma") return new LZMACompression();

    throw invalid_argument("Unknown compression algorithm: " + type);
}


int main(int argc, char* argv[]){
    try {
        switch(argc) {
            case 5: {
                string mode = argv[1];
                string inputFile = argv[2];
                string outputFile = argv[3];
                string algorithm = argv[4];
                
                Compression* compressor = createCompression(algorithm);

                if (mode == "-c") {
                    compressor->compress(inputFile, outputFile);
                } else if (mode == "-d") {
                    compressor->decompress(inputFile, outputFile);
                } else {
                    cout << "Invalid mode: " << mode << endl;
                    return 1;
                }
                delete compressor;
                break;
            }
            default:
                cout << "Usage: " << argv[0] << " -c|-d <inputFile> <outputFile> <algorithm>\n";
                return 1;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
}
