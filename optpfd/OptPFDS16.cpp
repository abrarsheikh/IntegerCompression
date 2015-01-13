/**
 OptPFDS16.cpp
 Purpose: OptPFDS16 implementation
 
 @author Abrar Sheikh
 @version 1.0
 */

#include <stdio.h>
#include <cmath>
#include "Utils.h"
#include "OptPFDS16.h"
#include "S16.h"
#include "BitPacking.h"


unsigned int OptPFDS16::headlessCompress(unsigned int* in, int inlength, unsigned int* out) {
    inlength = Utils::lcm(inlength, OptPFDS16::BLOCK_SIZE);
    if (inlength == 0)
        return -1;
    unsigned int *in_o = in;
    unsigned int *out_o = out;
    
    encodePage(&in, inlength, &out);
    return out - out_o + 1;
}

void OptPFDS16::getBestBFromData(unsigned int* in, int* bestb, int* bestexcept) {
    const int mb = Utils::maxbits(in, BLOCK_SIZE);
    int mini = 0;
    if (mini + 28 < bits[invbits[mb]])
        mini = bits[invbits[mb]] - 28; // 28 is the max for
    // exceptions
    int besti = bitscount - 1;
    int bestcost = bits[besti] * 4;
    int exceptcounter = 0;
    for (int i = mini; i < bitscount - 1; ++i) {
        int tmpcounter = 0;
        for (unsigned int *k = in; k < BLOCK_SIZE + in; ++k)
            if ((*k >> bits[i]) != 0) {
                ++tmpcounter;
            }
        if (tmpcounter == BLOCK_SIZE) {
            continue; // no need
        }
        for (unsigned int *k = in, c = 0; k < in + BLOCK_SIZE; ++k)
            if ((*k >> bits[i]) != 0) {
                exceptbuffer[tmpcounter + c] = k - in;
                exceptbuffer[c] = *k >> bits[i];
                ++c;
            }
        
        const int thiscost = bits[i] * 4 + S16::estimatecompress(exceptbuffer, 2 * tmpcounter);
        if (thiscost <= bestcost) {
            bestcost = thiscost;
            besti = i;
            exceptcounter = tmpcounter;
        }
    }
    *bestb = besti;
    *bestexcept = exceptcounter;
}

void OptPFDS16::encodePage(unsigned int** in, int thissize, unsigned int** out){
    unsigned int* tmpoutpos = *out;
    unsigned int* tmpinpos = *in;
    int bestb;
    int bestexcept;
    for (const unsigned int *finalinpos = tmpinpos + thissize; tmpinpos
         + BLOCK_SIZE <= finalinpos; tmpinpos += BLOCK_SIZE) {
        getBestBFromData(tmpinpos, &bestb, &bestexcept);
        const int tmpbestb = bestb;
        const int nbrexcept = bestexcept;
        int exceptsize = 0;
        unsigned int* const remember = tmpoutpos;
        tmpoutpos++;
        if (nbrexcept > 0) {
            int c = 0;
            for (int i = 0; i < BLOCK_SIZE; ++i) {
                if ((*(tmpinpos + i) >> bits[tmpbestb]) != 0) {
                    exceptbuffer[c + nbrexcept] = i;
                    exceptbuffer[c] = *(tmpinpos + i) >> bits[tmpbestb];
                    ++c;
                }
            }
            
            exceptsize = S16::compress(exceptbuffer, 2 * nbrexcept, tmpoutpos);
            tmpoutpos += exceptsize;
        }
        *remember = tmpbestb | (nbrexcept << 8) | (exceptsize << 16);
        for (int k = 0; k < BLOCK_SIZE; k += 32) {
            BitPacking::fastpack(tmpinpos + k, tmpoutpos, bits[tmpbestb]);
            //if(bits[tmpbestb] == 32)
                //std::cout  << *(tmpinpos + k)  << "\n";
            tmpoutpos += bits[tmpbestb];
        }
    }
    *in = tmpinpos;
    *out = tmpoutpos;
}

void OptPFDS16::headlessUncompress(unsigned int* in, int inlength, unsigned int* out, int mynvalue) {
    if (inlength == 0)
        return;
    mynvalue = Utils::lcm(mynvalue, BLOCK_SIZE);
    decodePage(in, out, mynvalue);
}

void OptPFDS16::decodePage(unsigned int* in,unsigned int* out, int thissize) {
    unsigned int* tmpoutpos = out;
    unsigned int* tmpinpos = in;
    
    for (int run = 0; run < thissize / BLOCK_SIZE; ++run, tmpoutpos += BLOCK_SIZE) {
        unsigned int b = *(tmpinpos) & 0xFF;
        unsigned int cexcept = (*(tmpinpos) >> 8) & 0xFF;
        unsigned int exceptsize = (*(tmpinpos) >> 16);
        ++tmpinpos;
        S16::uncompress(tmpinpos, exceptsize, exceptbuffer, 2 * cexcept);
        
        
        tmpinpos += exceptsize;
        for (int k = 0; k < BLOCK_SIZE; k += 32) {
            BitPacking::fastunpack(tmpinpos, tmpoutpos + k, bits[b]);
            tmpinpos += bits[b];
        }
        for (int k = 0; k < cexcept; ++k) {
            *(tmpoutpos + exceptbuffer[k + cexcept]) |= (exceptbuffer[k] << bits[b]);
        }
    }
    in = tmpinpos;
    out = tmpoutpos;
}

unsigned int OptPFDS16::compress(unsigned int* in, int inlength, unsigned int* out) {
    inlength = (int)ceil((1.0 * inlength) / BLOCK_SIZE) * BLOCK_SIZE;
    if (inlength == 0)
        return -1;
    *out = inlength;
    out++;
    return headlessCompress(in, inlength, out);
}

void OptPFDS16::uncompress(unsigned int* in, int inlength, unsigned int* out) {
    if (inlength == 0)
        return;
    const int outlength = *in;
    in++;
    headlessUncompress(in, inlength, out, outlength);
}

int OptPFDS16::bitscount = 17;

int OptPFDS16::bits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 16, 20, 32 };

int OptPFDS16::invbitscount = 33;

int OptPFDS16::invbits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16 };

OptPFDS16::OptPFDS16() {
    exceptbuffer = new unsigned int[2 * BLOCK_SIZE];
}


