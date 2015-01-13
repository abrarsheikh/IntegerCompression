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
#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif
#include <iostream>

class Timer {
public:
    Timer();
    
    void start();
    
    void end();
    
    long getDuration();
    
private:
    timespec ts_beg, ts_end;
    
    long duration;
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
    
    Timer compressionTimer;
    
    Timer decompressionTimer;
    
private:
     long originalSize = 0;
    
     long compressedSize = 0;
    
     static double getMiS(long size, long nanoTime);
};



#endif /* defined(__optpfd__Logger__) */
