#ifdef _MSC_VER
# if _MSC_VER >= 1700
#  pragma warning(disable:4447) // Disable warning 'main' signature found without threading model
# endif
#endif

#if defined __ANDROID__ || defined __linux__ || defined __FreeBSD__ || defined __HAIKU__
#  include <unistd.h>
#  include <fcntl.h>
#  include <elf.h>
#if defined __ANDROID__ || defined __linux__
#  include <linux/auxvec.h>
#endif
#endif

#if defined __ANDROID__ && defined HAVE_CPUFEATURES
#  include <cpu-features.h>
#endif

#ifndef __VSX__
# if defined __PPC64__ && defined __linux__
#   include "sys/auxv.h"
#   ifndef AT_HWCAP2
#     define AT_HWCAP2 26
#   endif
#   ifndef PPC_FEATURE2_ARCH_2_07
#     define PPC_FEATURE2_ARCH_2_07 0x80000000
#   endif
# endif
#endif

#if defined _WIN32 || defined WINCE
#include <windows.h>
#include <tchar.h>

#ifndef _WIN32_WINNT           // This is needed for the declaration of TryEnterCriticalSection in winbase.h with Visual Studio 2005 (and older?)
#define _WIN32_WINNT 0x0400    // http://msdn.microsoft.com/en-us/library/ms686857(VS.85).aspx
#endif

#if (_WIN32_WINNT >= 0x0602)
#include <synchapi.h>
#endif

#if defined _MSC_VER
#if _MSC_VER >= 1400
#include <intrin.h>
#endif
#endif

#ifdef WINRT
#include <wrl/client.h>
#ifndef __cplusplus_winrt
#include <windows.storage.h>
#pragma comment(lib, "runtimeobject.lib")
#endif
#endif

#else
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#if defined __MACH__ && defined __APPLE__
#include <mach/mach.h>
#include <mach/mach_time.h>
#endif

#endif

#include "Time.h"

long long getTickCount(void)
{
#if defined _WIN32 || defined WINCE
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	return (long long)counter.QuadPart;
#elif defined __linux || defined __linux__
	struct timespec tp;
	clock_gettime(CLOCK_MONOTONIC, &tp);
	return (long long)tp.tv_sec * 1000000000 + tp.tv_nsec;
#elif defined __MACH__ && defined __APPLE__
	return (long long)mach_absolute_time();
#else
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
#endif
}

double getTickFrequency(void)
{
#if defined _WIN32 || defined WINCE
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return (double)freq.QuadPart;
#elif defined __linux || defined __linux__
	return 1e9;
#elif defined __MACH__ && defined __APPLE__
	static double freq = 0;
	if (freq == 0)
	{
		mach_timebase_info_data_t sTimebaseInfo;
		mach_timebase_info(&sTimebaseInfo);
		freq = sTimebaseInfo.denom*1e9 / sTimebaseInfo.numer;
	}
	return freq;
#else
	return 1e6;
#endif
}

#if defined __GNUC__ && (defined __i386__ || defined __x86_64__ || defined __ppc__)
#if defined(__i386__)

long long getCPUTickCount(void)
{
	long long x;
	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
	return x;
}
#elif defined(__x86_64__)

long long getCPUTickCount(void)
{
	unsigned hi, lo;
	__asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
	return (long long)lo | ((long long)hi << 32);
}

#elif defined(__ppc__)

long long getCPUTickCount(void)
{
	long long result = 0;
	unsigned upper, lower, tmp;
	__asm__ volatile(
		"0:                  \n"
		"\tmftbu   %0           \n"
		"\tmftb    %1           \n"
		"\tmftbu   %2           \n"
		"\tcmpw    %2,%0        \n"
		"\tbne     0b         \n"
		: "=r"(upper), "=r"(lower), "=r"(tmp)
		);
	return lower | ((long long)upper << 32);
}

#else

#error "RDTSC not defined"

#endif

#elif defined _MSC_VER && defined _WIN32 && defined _M_IX86

long long getCPUTickCount(void)
{
	__asm _emit 0x0f;
	__asm _emit 0x31;
}

#else

long long getCPUTickCount(void)
{
	return getTickCount();
}

#endif

int mSleep(unsigned long msec)
{
#if defined(_WIN32)
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10000 * (__int64)msec);

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
	return 0;
#else
	return usleep(msec * 1000);
#endif
}

int uSleep(unsigned long usec)
{
#ifdef WIN32
	long long time1 = 0, time2 = 0, cost = 0, freq = 0;

	time1 = getTickCount();
	freq = (long long)getTickFrequency();

	for (;;) {
		time2 = getTickCount();
		cost = (time2 - time1) * 1000000 / freq;
		if (cost >= usec){
			return 0;
		} else {
			Sleep(0);
		}
	}
#else
	usleep(usec);
#endif
}
