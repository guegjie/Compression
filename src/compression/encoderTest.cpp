#include "RangeEncoder.h"
#include "file.h"

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace {
std::vector<uint8_t> g_emittedBytes;
}

void RangeEncoder::outputByte(uint8_t byte) {
    g_emittedBytes.push_back(byte);
    ++byteCount;
}

int main() {
    FileManager files;
    const std::vector<uint8_t> symbols = files.readFile("test/range_bits_01001_symbols.bin");

    if (symbols != std::vector<uint8_t>{0, 1, 0, 0, 1}) {
        throw std::runtime_error("Unexpected test input contents");
    }

    RangeEncoder encoder;
    for (uint8_t symbol : symbols) {
        if (symbol == 0) {
            encoder.encodeSymbol(0, 1, 2);
        } else if (symbol == 1) {
            encoder.encodeSymbol(1, 1, 2);
        } else {
            throw std::runtime_error("Input must only contain 0 and 1 symbols");
        }
    }
    encoder.flush();

    std::cout << "Encoded symbols: 01001\n";
    std::cout << "Expected final interval with a fixed 50/50 model: (0.28125, 0.3125)\n";
    std::cout << "Emitted bytes (" << g_emittedBytes.size() << "):";
    for (uint8_t byte : g_emittedBytes) {
        std::cout << " 0x"
                  << std::uppercase << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned>(byte);
    }
    std::cout << std::dec << "\n";

    return 0;
}
