/**
 Logger
 Purpose: Benchmark protoype declaration
 * Simple class meant to compare the speed of different schemes.

 @author Abrar Sheikh
 @version 1.0
 */

#ifndef __optpfd__Benchmark__
#define __optpfd__Benchmark__

#include <stdio.h>
#include <iostream>
#include "IntegerCompression.h" 
#include "OptPFDS16.h"
#include "ClusteredDataGenerator.h"
#include "Logger.h"
#include "Utils.h"

class Benchmark {
public:
    
    struct genData {
        unsigned int** data;
        int numOfArray;
        int lenOfArray;
    };
    
    /**
     * Standard benchmark
     *
     * @param c         the codec
     * @param data      arrays of input data
     * @param repeat    How many times to repeat the test
     * @param verbose   whether to output result on screen
     */
    static void testCodec(int sparsity, IntegerCompression& c, unsigned int ** data, genData gd, int repeat, bool verbose) ;
    
    /**
     * Generate test data.
     *
     * @param N             How many input arrays to generate
     * @param nbr           How big (in log2) should the arrays be
     * @param sparsity      How sparse test data generated
     */
    static unsigned int** generateTestData(ClusteredDataGenerator dataGen, int N, int nbr, int sparsity, genData* gd);
    
    /**
     * Generates data and calls other tests.
     *
     * @param N         How many input arrays to generate
     * @param nbr       how big (in log2) should the arrays be
     * @param repeat    How many times should we repeat tests.
     */
    static void test(int N, int nbr, int repeat);
    
};


#endif /* defined(__optpfd__Benchmark__) */
