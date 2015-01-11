/**
 UniformDataGenerator
 Purpose: UniformDataGenerator implementation
 
 @author Abrar Sheikh
 @version 1.0
 */

#include "UniformDataGenerator.h"
#include <map>
#include <bitset>

UniformDataGenerator::UniformDataGenerator() {
}

/**
 * @param seed
 *                random seed
 */
UniformDataGenerator::UniformDataGenerator(const int seed) {
}

/**
 * generates randomly N distinct integers from 0 to Max.
 */
unsigned int* UniformDataGenerator::generateUniformHash(int N, int Max) {
    if (N > Max)
        throw std::runtime_error("not possible");
    unsigned int* ans = new unsigned int[N];
    std::map<int, int> s;
    while (s.size() < N)
        s.insert(std::pair<int, int> (rand() % Max, 1));
    std::map<int, int>::iterator iter = s.begin();
    int k;
    for(k = 0; iter != s.end(); iter++)
    {
        ans[k++] = iter->first;
    }
    return ans;
}

/**
 * output all integers from the range [0,Max) that are not in the array
 */
unsigned int* UniformDataGenerator::negate(unsigned int* x, int Max) {
    int lenx = sizeof(x)/sizeof(x[0]);
    unsigned int* ans = new unsigned int[Max - lenx];
    int i = 0;
    int c = 0;
    for (int j = 0; j < lenx; ++j) {
        int v = x[j];
        for (; i < v; ++i)
            ans[c++] = i;
        ++i;
    }
    while (c < Max - lenx)
        ans[c++] = i++;
    return ans;
}

unsigned int* UniformDataGenerator::generateUniform(int N, int Max) {
    if (N * 2 > Max) {
        return negate(generateUniform(Max - N, Max), Max);
    }
    /*
    if (2048 * N > Max)
        return generateUniformBitmap(N, Max);
     */
    return generateUniformHash(N, Max);
}

/**
 * generates randomly N distinct integers from 0 to Max.
 */
unsigned int* UniformDataGenerator::generateUniformBitmap(int N, int Max) {
    unsigned int* a;
    return a;
}