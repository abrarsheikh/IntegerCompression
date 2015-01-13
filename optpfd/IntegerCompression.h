/**
 IntegerCompression.cpp
 Purpose: compression super class
 
 @author Abrar Sheikh
 @version 1.0
 */
#ifndef __optpfd__IntegerCompression__
#define __optpfd__IntegerCompression__

#include <stdio.h>

class IntegerCompression {
public:
    /**
     * Compress data from an array to another array.
     *
     * Both inpos and outpos are modified to represent how much data was
     * read and written to if 12 ints (inlength = 12) are compressed to 3
     * ints, then inpos will be incremented by 12 while outpos will be
     * incremented by 3 we use IntWrapper to pass the values by reference.
     *
     * @param in            input array
     * @param inlength      how many integers to compress
     * @param out           output array
     */
    virtual unsigned int compress(unsigned int* in, unsigned int inlength, unsigned int* out) {
        return 0;
    }
    
    /**
     * Uncompress data from an array to another array.
     *
     * Both inpos and outpos parameters are modified to indicate new
     * positions after read/write.
     *
     * @param in            array containing data in compressed form
     * @param inlength      length of the compressed data (ignored by some schemes)
     * @param out           array where to write the compressed output
     */
    virtual void uncompress(unsigned int* in, int inlength, unsigned int* out) {
        
    }
    
    /**
     * Compress data from an array to another array.
     *
     * Both inpos and outpos are modified to represent how much data was read
     * and written to if 12 ints (inlength = 12) are compressed to 3 ints, then
     * inpos will be incremented by 12 while outpos will be incremented by 3 we
     * use IntWrapper to pass the values by reference.
     *
     * @param in            input array
     * @param inlength      how many integers to compress
     * @param out           output array
     */
    virtual unsigned int headlessCompress(unsigned int* in, int inlength,unsigned int* out) {
        return 0;
    }
    
    /**
     * Uncompress data from an array to another array.
     *
     * Both inpos and outpos parameters are modified to indicate new positions
     * after read/write.
     *
     * @param in            array containing data in compressed form
     * @param inlength      length of the compressed data (ignored by some schemes)
     * @param out           array where to write the compressed output
     * @param num           number of integers we want to decode, the actual number of integers decoded can be less
     */

    virtual void headlessUncompress(unsigned int* in, int inlength, unsigned int* out, int num) {
        
    }
};

#endif /* defined(__optpfd__IntegerCompression__) */