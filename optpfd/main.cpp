//
//  main.cpp
//  optpfd
//
//  Created by Abrar Sheikh on 05/01/15.
//  Copyright (c) 2015 nyu. All rights reserved.
//

#include <iostream>

#include "S16.h"
#include "OptPFDS16.h"

void test_s16();
void test_optpfd();

int main(int argc, const char * argv[]) {
    // insert code here...
    test_s16();
    test_optpfd();
    return 0;
}

void test_optpfd() {
    unsigned int input[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 1, 1, 1};
    unsigned int *coded;
    unsigned int *output;
    
    int size = 128;
    
    coded = new unsigned int[size];
    output = new unsigned int[size];
    OptPFDS16 c;
    unsigned int newsize = c.compress(input, size, coded);
    c.uncompress(coded, newsize, output);
    
    printf("Normal size: %d\n", size);
    printf("Compress size: %d\n", newsize);
    for(int i = 0; i < size; i++) {
        printf("%u -> %X -> %u\n", input[i], coded[i], output[i]);
    }

}

void test_s16() {
    unsigned int input[] = {22402313,2,3,4,5,6,7,8,9,10};
    unsigned int *coded;
    unsigned int *output;
    
    int size = 10;
    int newsize;
    int i;
    
    coded = new unsigned int[size];
    output = new unsigned int[size];
    newsize = S16::compress(input, size, coded);
    S16::uncompress(coded, newsize, output, size);
    
    printf("Normal size: %d\n", size);
    printf("Compress size: %d\n", newsize);
    for(i = 0; i < size; i++) {
        printf("%u -> %X -> %u\n", input[i], coded[i], output[i]);
    }
}
