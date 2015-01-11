//
//  Utils.cpp
//  optpfd
//
//  Created by Abrar Sheikh on 08/01/15.
//  Copyright (c) 2015 nyu. All rights reserved.
//

#include "Utils.h"


int Utils::gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int Utils::lcm(int a, int b)
{
    int temp = gcd(a, b);
    
    return temp ? (a / temp * b) : 0;
}

int Utils::maxbits(unsigned int* i, int length) {
    int mask = 0;
    
    for (unsigned int *k = i; k < i + length; ++k)
        mask |= *k;
    return Utils::bits(mask);
}

int Utils::bits(int i) {
    return 32 - numberOfLeadingZeros(i);
}

unsigned Utils::numberOfLeadingZeros(int x){
    unsigned n = 0;
    if (x == 0) return sizeof(x) * 8;
    while (1) {
        if (x < 0) break;
        n ++;
        x <<= 1;
    }
    return n;
}