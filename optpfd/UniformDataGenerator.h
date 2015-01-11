/**
 UniformDataGenerator
 Purpose: UniformDataGenerator prototype defination
            This class will generate "uniform" lists of random integers.
 
 @author Abrar Sheikh
 @version 1.0
 */

#ifndef __optpfd__UniformDataGenerator__
#define __optpfd__UniformDataGenerator__

#include <stdio.h>
#include <iostream>

class UniformDataGenerator {
public:
    /**
     * construct generator of random arrays.
     */
    UniformDataGenerator();
    
    /**
     * @param seed      random seed
     */
    UniformDataGenerator(const int seed);
    
    /**
     * generates randomly N distinct integers from 0 to Max.
     *
     * @param N
     *                number of integers to generate
     * @param Max
     *                bound on the value of integers
     * @return an array containing randomly selected integers
     */
    unsigned int* generateUniform(int N, int Max);
    
private:
    
    /**
     * generates randomly N distinct integers from 0 to Max.
     */
    unsigned int* generateUniformHash(int N, int Max);
    
    /**
     * output all integers from the range [0,Max) that are not in the array
     */
    static unsigned int* negate(unsigned int* x, int Max);
    
    /**
     * generates randomly N distinct integers from 0 to Max.
     */
    unsigned int* generateUniformBitmap(int N, const int Max);
    
};

#endif /* defined(__optpfd__UniformDataGenerator__) */
