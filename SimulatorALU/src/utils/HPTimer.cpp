/*
 * HPTimer.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: dunlap
 */

#include "HPTimer.h"

#ifdef WIN32

#include <windows.h>
double HPTimer::get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

double HPTimer::get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

#endif
