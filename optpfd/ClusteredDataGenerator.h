/**
 ClusteredDataGenerator.h
 Purpose: ClusteredDataGenerator prototype defination
 
 * This class will generate lists of random integers based on the clustered
 * model:
 *
 * Reference: Vo Ngoc Anh and Alistair Moffat. 2010. Index compression using
 * 64-bit words. Softw. Pract. Exper.40, 2 (February 2010), 131-147.
 
 @author Abrar Sheikh
 @version 1.0
 */

#ifndef __optpfd__ClusteredDataGenerator__
#define __optpfd__ClusteredDataGenerator__

#include <stdio.h>
#include <iostream>
#include "UniformDataGenerator.h"

class ClusteredDataGenerator {
public:
    UniformDataGenerator unidg;
    
    /**
     * Creating random array generator.
     */
    ClusteredDataGenerator();
    /**
     * generates randomly N distinct integers from 0 to Max.
     *
     * @param N
     *                number of integers to generate
     * @param Max
     *                maximal value of the integers
     * @return array containing the integers
     */
    unsigned int* generateClustered(int N, int Max);
    
private:
    
    
    void fillUniform(unsigned int* array, int length, int Min, int Max);
    
    void fillClustered(unsigned int* array, int length, int Min, int Max);
    
    
};

#endif /* defined(__optpfd__ClusteredDataGenerator__) */
