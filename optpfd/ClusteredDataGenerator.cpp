/**
 ClusteredDataGenerator.cpp
 Purpose: ClusteredDataGenerator implementation
 
 @author Abrar Sheikh
 @version 1.0
 */

#include "ClusteredDataGenerator.h"
#include "UniformDataGenerator.h"



/**
 * Creating random array generator.
 */
ClusteredDataGenerator::ClusteredDataGenerator() {
    UniformDataGenerator udg;
    unidg = udg;
}

void ClusteredDataGenerator::fillUniform(unsigned int* array, int length, int Min, int Max) {
    unsigned int* v = unidg.generateUniform(length, Max - Min);
    for (int k = 0; k < length; ++k)
        *(array + k) = Min + v[k];
}

void ClusteredDataGenerator::fillClustered(unsigned int* array, int length, int Min, int Max) {
    const int range = Max - Min;
    if ((range == length) || (length <= 10)) {
        fillUniform(array, length, Min, Max);
        return;
    }
    const int cut = length / 2 + ((range - length - 1 > 0) ? rand() % (range - length - 1) : 0);
    const double p = rand();
    if (p < 0.25) {
        fillUniform(array, length / 2, Min, Min + cut);
        fillClustered(array + length / 2, length
                      - length / 2, Min + cut, Max);
    } else if (p < 0.5) {
        fillClustered(array, length / 2, Min, Min + cut);
        fillUniform(array + length / 2, length - length
                    / 2, Min + cut, Max);
    } else {
        fillClustered(array, length / 2, Min, Min + cut);
        fillClustered(array + length / 2, length
                      - length / 2, Min + cut, Max);
    }
}

/**
 * generates randomly N distinct integers from 0 to Max.
 *
 * @param N
 *                number of integers to generate
 * @param Max
 *                maximal value of the integers
 * @return array containing the integers
 */
unsigned int* ClusteredDataGenerator::generateClustered(int N, int Max) {
    unsigned int* array = new unsigned int[N];
    fillClustered(array, N, 0, Max);
    return array;
}

/**
 * Little test program.
 *
 * @param args
 *                arguments are ignored
 */