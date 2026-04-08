#include "core/RangeEncoder.h"
#include <cstdint>


RangeEncoder::RangeEncoder() {
    low = 0;
    range = TOPVALUE;
    buffer = 0;
    help = 0;
    byteCount = 0;
}

void RangeEncoder::renormalize() {
    while(range<= BOTTOMVALUE){
        if(low < (0b11111111ULL<<SHIFTBITS)){
            outputByte(buffer);
            for(;help != 0; --help){
                outputByte(0b11111111);
            }
            buffer = low >> SHIFTBITS;
        }else{
            if((low & TOPVALUE) != 0){
                outputByte(buffer + 1);
                for(;help != 0; --help){
                    outputByte(0b00000000);
                }
                buffer = low >> SHIFTBITS;
            }else {
                ++help; //note: source says ++buffer but i think it should be ++help
            }
        }
        range <<= 8;
        low <<= 8;
        low &= (TOPVALUE - 1);
    }
}


void RangeEncoder::encodeSymbol(uint32_t cumalitiveFreq, uint32_t freq, uint32_t total){
    renormalize();
    size_t r = range/total;
    size_t temp = r*cumalitiveFreq;
    if(cumalitiveFreq+freq < total){
        range = r*freq;
    }else{
        range -= temp;
    }
    low += temp;
}

void RangeEncoder::flush(){
    renormalize();
    size_t temp = low>>23;
    if(temp>0b11111111){
        outputByte(buffer+1);
        for(;help != 0; --help){
            outputByte(0b00000000);
        }
    }else{
        outputByte(buffer);
        for(;help != 0; --help){
            outputByte(0b11111111);
        }
    }
    outputByte(temp & 0b11111111);
    outputByte((temp=low>>(23-8))&0b11111111);
}