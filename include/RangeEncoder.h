#ifndef RE_H
#define RE_H
#include "file.h"
#include <cstdint>

/* 
    article: ranger coder from 1999 written by Arturo Campossource 
    article link: https://web.archive.org/web/20061206022614/http://www.arturocampos.com/ac_range.html#Encoder%20Implementation
    (via wayback machine)
*/
class RangeEncoder {
public:
    RangeEncoder();
    void encodeSymbol(uint32_t cumalitiveFreq, uint32_t freq, uint32_t total);
    void renormalize();
    void flush();

private:
    void outputByte(uint8_t byte);
    uint64_t low;
    uint32_t range;
    uint8_t buffer;
    uint32_t help;
    uint64_t byteCount;

    //constants
    //taken straight from the article
    uint32_t TOPVALUE = 0x80000000;
    uint32_t BOTTOMVALUE = 0x00800000;
    uint32_t SHIFTBITS = 23;
};

#endif
