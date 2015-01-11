/**
 BitPacking.h
 Purpose: BitPacking prototype defination
 
 @author Abrar Sheikh
 @version 1.0
 */

#ifndef __optpfd__BitPacking__
#define __optpfd__BitPacking__


#include <stdio.h>
#include <iostream>

class BitPacking {
    
public:
    /**
     * Pack 32 integers
     *
     * @param in        source array
     * @param out       output array
     * @param bit       number of bits to use per integer
     */
    static void fastpack(const unsigned int* in, unsigned int* out, const int bit) ;
    
    /**
     * Unpack 32 integers
     *
     * @param in        source array
     * @param out       output array
     * @param bit       number of bits to use per integer
     */
    static void fastpackwithoutmask(const unsigned int* in,  unsigned int* out, const int bit) ;
    
    /**
     * Pack the 32 integers
     *
     * @param in        source array
     * @param out       output array
     * @param bit       how many bits to use per integer
     */
    static void fastunpack(const unsigned int* in, unsigned int* out, const int bit) ;
    
protected:
    static void fastpack0(const unsigned int* in, unsigned int* out) ;
    static void fastpack1(const unsigned int* in, unsigned int* out) ;
    static void fastpack10(const unsigned int* in, unsigned int* out) ;
    static void fastpack11(const unsigned int* in, unsigned int* out) ;
    static void fastpack12(const unsigned int* in, unsigned int* out) ;
    static void fastpack13(const unsigned int* in, unsigned int* out) ;
    static void fastpack14(const unsigned int* in, unsigned int* out) ;
    static void fastpack15(const unsigned int* in, unsigned int* out) ;
    static void fastpack16(const unsigned int* in, unsigned int* out) ;
    static void fastpack17(const unsigned int* in, unsigned int* out) ;
    static void fastpack18(const unsigned int* in, unsigned int* out) ;
    static void fastpack19(const unsigned int* in, unsigned int* out) ;
    static void fastpack2(const unsigned int* in, unsigned int* out) ;
    static void fastpack20(const unsigned int* in, unsigned int* out) ;
    static void fastpack21(const unsigned int* in, unsigned int* out) ;
    static void fastpack22(const unsigned int* in, unsigned int* out) ;
    static void fastpack23(const unsigned int* in, unsigned int* out) ;
    static void fastpack24(const unsigned int* in, unsigned int* out) ;
    static void fastpack25(const unsigned int* in, unsigned int* out) ;
    static void fastpack26(const unsigned int* in, unsigned int* out) ;
    static void fastpack27(const unsigned int* in, unsigned int* out) ;
    static void fastpack28(const unsigned int* in, unsigned int* out) ;
    static void fastpack29(const unsigned int* in, unsigned int* out) ;
    static void fastpack3(const unsigned int* in, unsigned int* out) ;
    static void fastpack30(const unsigned int* in, unsigned int* out) ;
    static void fastpack31(const unsigned int* in, unsigned int* out) ;
    static void fastpack32(const unsigned int* in, unsigned int* out) ;
    static void fastpack4(const unsigned int* in, unsigned int* out) ;
    static void fastpack5(const unsigned int* in, unsigned int* out) ;
    static void fastpack6(const unsigned int* in, unsigned int* out) ;
    static void fastpack7(const unsigned int* in, unsigned int* out) ;
    static void fastpack8(const unsigned int* in, unsigned int* out) ;
    static void fastpack9(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask0(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask1(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask10(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask11(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask12(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask13(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask14(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask15(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask16(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask17(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask18(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask19(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask2(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask20(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask21(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask22(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask23(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask24(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask25(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask26(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask27(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask28(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask29(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask3(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask30(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask31(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask32(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask4(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask5(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask6(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask7(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask8(const unsigned int* in, unsigned int* out) ;
    static void fastpackwithoutmask9(const unsigned int* in, unsigned int* out) ;
    static void fastunpack0(const unsigned int* in, unsigned int* out) ;
    static void fastunpack1(const unsigned int* in, unsigned int* out) ;
    static void fastunpack10(const unsigned int* in, unsigned int* out) ;
    static void fastunpack11(const unsigned int* in, unsigned int* out) ;
    static void fastunpack12(const unsigned int* in, unsigned int* out) ;
    static void fastunpack13(const unsigned int* in, unsigned int* out) ;
    static void fastunpack14(const unsigned int* in, unsigned int* out) ;
    static void fastunpack15(const unsigned int* in, unsigned int* out) ;
    static void fastunpack16(const unsigned int* in, unsigned int* out) ;
    static void fastunpack17(const unsigned int* in, unsigned int* out) ;
    static void fastunpack18(const unsigned int* in, unsigned int* out) ;
    static void fastunpack19(const unsigned int* in, unsigned int* out) ;
    static void fastunpack2(const unsigned int* in, unsigned int* out) ;
    static void fastunpack20(const unsigned int* in, unsigned int* out) ;
    static void fastunpack21(const unsigned int* in, unsigned int* out) ;
    static void fastunpack22(const unsigned int* in, unsigned int* out) ;
    static void fastunpack23(const unsigned int* in, unsigned int* out) ;
    static void fastunpack24(const unsigned int* in, unsigned int* out) ;
    static void fastunpack25(const unsigned int* in, unsigned int* out) ;
    static void fastunpack26(const unsigned int* in, unsigned int* out) ;
    static void fastunpack27(const unsigned int* in, unsigned int* out) ;
    static void fastunpack28(const unsigned int* in, unsigned int* out) ;
    static void fastunpack29(const unsigned int* in, unsigned int* out) ;
    static void fastunpack3(const unsigned int* in, unsigned int* out) ;
    static void fastunpack30(const unsigned int* in, unsigned int* out) ;
    static void fastunpack31(const unsigned int* in, unsigned int* out) ;
    static void fastunpack32(const unsigned int* in, unsigned int* out) ;
    static void fastunpack4(const unsigned int* in, unsigned int* out) ;
    static void fastunpack5(const unsigned int* in, unsigned int* out) ;
    static void fastunpack6(const unsigned int* in, unsigned int* out) ;
    static void fastunpack7(const unsigned int* in, unsigned int* out) ;
    static void fastunpack8(const unsigned int* in, unsigned int* out) ;
    static void fastunpack9(const unsigned int* in, unsigned int* out) ;
};

#endif /* defined(__optpfd__BitPacking__) */
