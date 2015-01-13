/**
 Logger
 Purpose: Logger Implementation
 
 @author Abrar Sheikh
 @version 1.0
 */

#include "Logger.h"
        
Timer::Timer() {
    duration = 0;
}
        
void Timer::start() {
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts_beg.tv_sec = mts.tv_sec;
    ts_beg.tv_nsec = mts.tv_nsec;
    
#else
    clock_gettime(CLOCK_REALTIME, &ts_beg);
#endif
}
        
void Timer::end() {
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts_end.tv_sec = mts.tv_sec;
    ts_end.tv_nsec = mts.tv_nsec;
    
#else
    clock_gettime(CLOCK_REALTIME, &ts_end);
#endif
}

long Timer::getDuration() {
    return (ts_end.tv_sec - ts_beg.tv_sec)*1e9 + (ts_end.tv_nsec - ts_beg.tv_nsec);
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


