/**
 IntegerCompression.cpp
 Purpose: compression super class
 
 @author Abrar Sheikh
 @version 1.0
 */

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
    void compress(int* in, unsigned int inpos, unsigned int inlength,
                         int* out, unsigned int outpos);
    
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
    void uncompress(int* in, unsigned int inpos, int inlength,
                           int* out, unsigned int outpos);
    
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
    void headlessCompress(int* in, unsigned int inpos, int inlength, int* out,
                                 unsigned int outpos);
    void headlessUncompress(int* in, unsigned int inpos, int inlength, int* out,
                                   unsigned int outpos, int num);
};