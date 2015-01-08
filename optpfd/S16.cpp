/**
 S16.cpp
 Purpose: S16 implementation
 
 @author Abrar Sheikh
 @version 1.0
 */

#include "S16.h"

int S16::compress(unsigned int *in, int inlength,unsigned int *out) {
    unsigned int *outpos = out;
    int counter = 0;
    const unsigned int *finalin = in + inlength;
    while (in < finalin) {
        int inoffset = compressblock(outpos++, in, inlength);
        if (inoffset == -1)
            throw std::runtime_error("Too big a number\n");
        in += inoffset;
        inlength -= inoffset;
        counter++;
    }
    return counter;
}

int S16::estimatecompress(unsigned int *in, int inlength) {
    const unsigned int *finalin = in + inlength;
    int counter = 0;
    while (in < finalin) {
        int inoffset = fakecompressblock(in++, inlength);
        if (inoffset == -1)
            throw std::runtime_error("Too big a number\n");
        in += inoffset;
        inlength -= inoffset;
        ++counter;
    }
    return counter;
}

int S16::compressblock(unsigned int *out,unsigned int *in, int n) {
    int numIdx, j, num, bits;
    for (numIdx = 0; numIdx < S16_NUMSIZE; numIdx++) {
        *out = numIdx << S16_BITSSIZE;
        num = (S16_NUM[numIdx] < n) ? S16_NUM[numIdx] : n;
        
        for (j = 0, bits = 0; (j < num)
             && (*(in + j) < SHIFTED_S16_BITS[numIdx][j]);) {
            *out |= (*(in + j) << bits);
            bits += S16_BITS[numIdx][j];
            j++;
        }
        
        if (j == num) {
            return num;
        }
    }
    
    return -1;
}

int S16::fakecompressblock(unsigned int *in, int n) {
    int numIdx, j, num;
    for (numIdx = 0; numIdx < S16_NUMSIZE; numIdx++) {
        num = (S16_NUM[numIdx] < n) ? S16_NUM[numIdx] : n;
        
        for (j = 0; (j < num)
             && (*(in + j) < SHIFTED_S16_BITS[numIdx][j]);) {
            j++;
        }
        
        if (j == num) {
            return num;
        }
    }
    
    return -1;
}

int S16::decompressblock(unsigned int* out,unsigned int* in, int n) {
    int numIdx, j = 0, bits = 0;
    numIdx = *in >> S16_BITSSIZE;
    int num = S16_NUM[numIdx] < n ? S16_NUM[numIdx] : n;
    for (j = 0, bits = 0; j < num; j++) {
        *(out + j) = (*(in) >> bits)
        & (0xffffffff >> (32 - S16_BITS[numIdx][j]));
        bits += S16_BITS[numIdx][j];
    }
    return num;
}

void S16::uncompress(unsigned int* in, int inlength,unsigned int* out, int outlength) {
    unsigned int *finalpos = in + inlength;
    while (in < finalpos) {
        const int howmany = decompressblock(out, in, outlength);
        outlength -= howmany;
        out += howmany;
        in += 1;
    }
}

int** S16::shiftme(int x[16][28]) {
    int **answer = new int*[16];
    for (int k = 0; k < 16; ++k) {
        answer[k] = new int[28];
        for (int z = 0; z < 28 && x[k][z] != 0; ++z)
            answer[k][z] = 1 << x[k][z];
    }
    return answer;
}

int S16::S16_NUM[] = { 28, 21, 21, 21, 14, 9, 8, 7, 6,
    6, 5, 5, 4, 3, 2, 1 };

int S16::S16_BITS[16][28] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {4,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {3,4,4,4,4,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {5,5,5,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {4,4,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {6,6,6,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {5,5,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {10,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

int** S16::SHIFTED_S16_BITS = S16::shiftme(S16::S16_BITS);


