/**
 Logger
 Purpose: Logger Implementation
 
 @author Abrar Sheikh
 @version 1.0
 */

#include "Logger.h"


std::chrono::system_clock::time_point Timer::startNano;
long Timer::duration = 0;
        
Timer::Timer() {
}
        
void Timer::start() {
    Timer::startNano = std::chrono::system_clock::now();
}
        
long Timer::end() {
    return Timer::duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - Timer::startNano).count();
}

long Timer::getDuration() {
    return duration;
}

PerformanceLogger::PerformanceLogger() {
    originalSize = 0;
    
    compressedSize = 0;
}

long PerformanceLogger::addOriginalSize(long value) {
    return originalSize += value;
}

long PerformanceLogger::addCompressedSize(long value) {
    return compressedSize += value;
}

long PerformanceLogger::getOriginalSize() {
    return originalSize;
}

long PerformanceLogger::getCompressedSize() {
    return compressedSize;
}

double PerformanceLogger::getBitPerInt() {
    return compressedSize * 32.0 / originalSize;
}

double PerformanceLogger::getMiS(long size, long nanoTime) {
    return (size * 1e-6) / (nanoTime * 1.0e-9);
}

double PerformanceLogger::getCompressSpeed() {
    return PerformanceLogger::getMiS(originalSize,
                                     compressionTimer.getDuration());
}

double PerformanceLogger::getDecompressSpeed() {
    return PerformanceLogger::getMiS(originalSize,
                                     decompressionTimer.getDuration());
}


