/**
 OptPFDS16.h
 Purpose: OptPFDS16 prototype declaration
 
 @author Abrar Sheikh
 @version 1.0
 */

#ifndef optpfd_OptPFDS16_h
#define optpfd_OptPFDS16_h

#include "IntegerCompression.h"


class OptPFDS16 :  public IntegerCompression  {
    
    /**
     * Constructor for the OptPFDS16 CODEC.
     */
public:
    OptPFDS16();
    virtual unsigned int headlessCompress(unsigned int* in, int inlength, unsigned int* out) ;
    
    virtual void headlessUncompress(unsigned int* in, int inlength, unsigned int* out, int mynvalue);
    
    virtual unsigned int compress(unsigned int* in, int inlength, unsigned int* out);
    
    virtual void uncompress(unsigned int* in, int inlength, unsigned int* out);
    
private:
    static int bitscount;
    static int bits[];
    static int invbitscount;
    static int invbits[];
    
    void getBestBFromData(unsigned int* in,  int* bestb, int* bestexcept);
    
    void encodePage(unsigned int** in, int thissize, unsigned int** out);
    
    void decodePage(unsigned int* in,unsigned int* out, int thissize);
    
    const static int BLOCK_SIZE = 128;
    unsigned int* exceptbuffer;
    
};
#endif
