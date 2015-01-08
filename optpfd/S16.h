/**
 S16.h
 Purpose: S16 prototype declaration
 
 @author Abrar Sheikh
 @version 1.0
 */

#ifndef __optpfd__S16__
#define __optpfd__S16__

#include <stdio.h>
#include <iostream>


class S16 {
public:
    /**
     * Compress an integer array using Simple16
     *
     *
     * @param in            array to compress
     * @param inlength      how many integers to read
     * @param out           output array
     * @return the number of 32-bit words written (in compressed form)
     */
    static int compress(unsigned int *in, int inlength,unsigned int *out);
    
    /**
     * Estimate size of the compressed output.
     *
     * @param in            array to compress
     * @param inlength      how many integers to read
     * @return estimated size of the output (in 32-bit integers)
     */
    static int estimatecompress(unsigned int *in, int inlength);
    
    /**
     * Compress an integer array using Simple16
     *
     * @param out           the compressed output
     * @param in            the integer input array
     * @param n             the number of elements to be compressed
     * @return the size of the outputs in 32-bit integers
     *
     */
    static int compressblock(unsigned int *out,unsigned int *in, int n);
    
    /**
     * Decompress an integer array using Simple16
     *
     * @param out               the decompressed output
     * @param in                the compressed input array
     * @param n                 the number of elements to be compressed
     * @return the number of processed integers
     */
    static int decompressblock(unsigned int* out,unsigned int* in, int n);
    
    /**
     * Uncompressed data from an input array into an output array
     *
     * @param in            input array (in compressed form)
     * @param inlength      how much data we wish the read (in 32-bit words)
     * @param out           output array (in decompressed form)
     * @param outlength     available data in the output array
     */
    static void uncompress(unsigned int* in, int inlength,unsigned int* out, int outlength) ;

private:
    
    static int fakecompressblock(unsigned int *in, int n);
    
    static int** shiftme(int x[16][28]) ;
    
    static int S16_NUM[];
    // the corresponding number of elements for each value of the number of
    // bits
    static const int S16_NUMSIZE = 16;
    static const int S16_BITSSIZE = 28;
    static int S16_BITS[16][28];
    static int** SHIFTED_S16_BITS;
};


#endif /* defined(__optpfd__S16__) */
