//
//  Benchmark.cpp
//  optpfd
//
//  Created by Abrar Sheikh on 11/01/15.
//  Copyright (c) 2015 nyu. All rights reserved.
//

#include "Benchmark.h"

void Benchmark::testCodec(int sparsity, OptPFDS16& c, unsigned int** data, genData gd, int repeat, bool verbose) {
    if (verbose) {
        //std::cout "# " << c.toString() << "\n";
        std::cout << ("# bits per int, compress speed (mis), decompression speed (mis) ");
    }
    
    int N = gd.numOfArray;
    
    int totalSize = 0;
    int totalCompressSize = 0;
    int maxLength = 0;
    for (int k = 0; k < N; ++k) {
        totalSize += gd.lenOfArray;
        if (gd.lenOfArray > maxLength) {
            maxLength = gd.lenOfArray;
        }
    }
    
    // 4x + 1024 to account for the possibility of some negative
    // compression.
    unsigned int* compressBuffer = new unsigned int[4 * maxLength + 1024];
    unsigned int* decompressBuffer = new unsigned int[maxLength + 1024];
    
    // These variables hold time in microseconds (10^-6).
    long compressTime = 0;
    long decompressTime = 0;
    
    PerformanceLogger pl;
    
    int size = 0;
    
    for (int r = 0; r < repeat; ++r) {
        size = 0;
        for (int k = 0; k < N; ++k) {
            unsigned int* backupdata;
            backupdata = new unsigned int[gd.lenOfArray];
            unsigned int compBuffSize = 0;
            
            
            Utils::arrCpy(backupdata, data[k], gd.lenOfArray);
            
            pl.compressionTimer.start();
            compBuffSize = c.compress(backupdata, gd.lenOfArray, compressBuffer);
            size += compBuffSize;
            pl.compressionTimer.end();
            
            // measure time of compression.
            compressTime += pl.compressionTimer.getDuration();
            
            // extract (uncompress) data
            pl.decompressionTimer.start();
            c.uncompress(compressBuffer, compBuffSize, decompressBuffer);
            
            pl.decompressionTimer.end();
            // measure time of extraction (uncompression).
            decompressTime += pl.decompressionTimer.getDuration();
            
            // verify: compare original array with
            // compressed and
            // uncompressed.
            
            for (int m = 0; m < gd.lenOfArray; ++m) {
                if (decompressBuffer[m] != data[k][m]) {
                    throw std::runtime_error("we have a bug (actual difference), expected " + std::to_string(data[k][m]) + " found " + std::to_string(decompressBuffer[m]) + " at " + std::to_string(m));
                }
            }
        }
    }
    
    if (verbose) {
        double bitsPerInt = size * 32.0 / totalSize;
        double compressSpeed = (totalSize * repeat * 1000.0) / (compressTime);
        double decompressSpeed = (size * repeat * 1000.0) / (decompressTime);
        printf("\t%1$.2f\t%2$f\t%3$f", bitsPerInt, compressSpeed, decompressSpeed);
    }
}


unsigned int** Benchmark::generateTestData(ClusteredDataGenerator dataGen, int N, int nbr, int sparsity, genData* gd) {
    const int dataSize = (1 << (nbr + sparsity));
    unsigned int** data;
    data = new unsigned int *[N];
    for (int i = 0; i < N; ++i) {
        data[i] = dataGen.generateClustered((1 << nbr), dataSize);
    }
    
    gd->numOfArray = N;
    gd->lenOfArray = (1 << nbr);
    
    return data;
}

void Benchmark::test(int N, int nbr, int repeat) {
    //csvLog.format("\"Algorithm\",\"Sparsity\",\"Bits per int\",\"Compress speed (MiS)\",\"Decompress speed (MiS)\"\n");
    ClusteredDataGenerator cdg;
    const int max_sparsity = 31 - nbr;
    for (int sparsity = 1; sparsity < max_sparsity; ++sparsity) {
        std::cout << "# sparsity " << sparsity << "\n";
        std::cout << "# generating random data..." << "\n";
        Benchmark::genData gd;
        unsigned int ** data;
        data = generateTestData(cdg, N, nbr, sparsity, &gd);
        std::cout << "# generating random data... ok." << "\n";
        OptPFDS16 optPFDS16;
        testCodec(sparsity, optPFDS16, data, gd, repeat, false);
        testCodec(sparsity, optPFDS16, data, gd, repeat, false);
        testCodec(sparsity, optPFDS16, data, gd, repeat, true);
        std::cout << "\n";
        
    }
}
