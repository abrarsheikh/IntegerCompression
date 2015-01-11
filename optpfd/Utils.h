//
//  Utils.h
//  optpfd
//
//  Created by Abrar Sheikh on 08/01/15.
//  Copyright (c) 2015 nyu. All rights reserved.
//

#ifndef optpfd_Utils_h
#define optpfd_Utils_h

class Utils {
public:
    static int gcd(int a, int b);
    
    static int lcm(int a, int b);
    
    /**
     * Compute the maximum of the integer logarithms (ceil(log(x+1)) of a range
     * of value
     *
     * @param i         source array
     * @param length    number of integers to consider
     * @return integer logarithm
     */
    static int maxbits(unsigned int* i, int length);
    
    static int bits(int i);
    
    static unsigned numberOfLeadingZeros(int x);
    
};

#endif
