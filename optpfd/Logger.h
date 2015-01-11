/**
 Logger
 Purpose: Logger prototype defination
 
 @author Abrar Sheikh
 @version 1.0
 */

#ifndef __optpfd__Logger__
#define __optpfd__Logger__

#include <stdio.h>
#include <chrono>

class Timer {
public:
    Timer();
    
    static void start();
    
    static long end();
    
    static long getDuration();
    
private:
    static std::chrono::system_clock::time_point startNano;
    
    static long duration;
};

class PerformanceLogger {
public:
    PerformanceLogger();
    long addOriginalSize(long value);
    
    long addCompressedSize(long value);
    
    long getOriginalSize();
    
    long getCompressedSize();
    
    double getBitPerInt();
    
    double getCompressSpeed();
    
    double getDecompressSpeed();
    
    const Timer compressionTimer;
    
    const Timer decompressionTimer;
    
private:
     long originalSize = 0;
    
     long compressedSize = 0;
    
     static double getMiS(long size, long nanoTime);
};



#endif /* defined(__optpfd__Logger__) */
