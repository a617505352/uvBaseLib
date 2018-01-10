#ifndef _UV_LIB_TIME_H_
#define _UV_LIB_TIME_H_

/**
* ©¥©¥©¥©¥©¥ÉñÊÞ³öÃ»©¥©¥©¥©¥©¥©¥
*¡¡¡¡¡¡¡¡©³©·¡¡    ©³©·
*¡¡¡¡¡¡©³©¿©ß©¥©¥©¥©¿©ß©·
*¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡  ©§ ¡¡
*¡¡¡¡¡¡©§      ©¥¡¡¡¡  ©§
*¡¡¡¡¡¡¨€¨€¨€¨€©¥¨€¨€¨€¨€
*¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡¡¡©§
*¡¡¡¡¡¡©§¡¡¡¡¡¡©ß¡¡¡¡¡¡©§
*¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡	   ©§
*¡¡¡¡¡¡©»©¥©·¡¡¡¡¡¡©³©¥©¿
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§¡¡¡¡
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
*¡¡¡¡¡¡¡¡¡¡©§¡¡ ¡¡ ©»©¥©¥©¥©·
*¡¡¡¡¡¡¡¡¡¡©§ ¡¡¡¡¡¡¡¡     ©Ç©·
*¡¡¡¡¡¡¡¡¡¡©§ ¡¡¡¡¡¡¡¡¡¡   ©³©¿
*¡¡¡¡¡¡¡¡¡¡©»©·©·©³©¥©×©·©³©¿
*¡¡¡¡¡¡¡¡¡¡¡¡©§©Ï©Ï  ©§©Ï©Ï
*¡¡¡¡¡¡¡¡¡¡¡¡©»©ß©¿  ©»©ß©¿
*
* Create by chen, 2018/1/10
**/

/**
* The function returns the number of ticks since the certain event(e.g. when the machine was turned on)
* The granularity of ticks depends on the hardware and OS used.
* copy from opencv
*/
long long getTickCount();

/**
* Returns the number of ticks per seconds.
*
* The function returns the number of ticks (as returned by getTickCount()) per second.
* The following code computes the execution time in milliseconds:
* copy from opencv
*
* \code
* double exec_time = (double)getTickCount();
* // do something ...
* exec_time = ((double)getTickCount() - exec_time)*1000./getTickFrequency();
* \endcode
*/
double getTickFrequency();

/**
* Returns the number of CPU ticks.
*
* On platforms where the feature is available, the function returns the number of CPU ticks
* since the certain event (normally, the system power-on moment). Using this function
* one can accurately measure the execution time of very small code fragments,
* for which getTickCount() granularity is not enough.
* copy from opencv
*
* \code
* double exec_time = (double)getTickCount();
* // do something ...
* exec_time = ((double)getTickCount() - exec_time)/getTickFrequency();
* \endcode
*/
long long getCPUTickCount();

/**
* Sleep for a period of time.  Although the duration is expressed in
* milliseconds, the actual delay may be rounded to the precision of the
* system timer, The actual timer accuracy depends on the capability of your hardware.
*
* In windows, call the timeGetDevCaps() function to determine the supported minimum timer resolution 
* and the timeBeginPeriod() function to set the timer resolution to its minimum.
* If you call timeBeginPeriod(), call it one time early in the application 
* and be sure to call the timeEndPeriod() function at the very end of the application.
* more accurate than Sleep() function in windows platform.
*
* usec Number of milliseconds to sleep.
*/
int mSleep(unsigned long msec);

/**
* Sleep for a period of time.  Although the duration is expressed in
* microseconds, the actual delay may be rounded to the precision of the
* system timer, The actual timer accuracy depends on the capability of your hardware.
*
* In windows, use QueryPerformanceCounter and Sleep(0) to realize this function.
* This is a busy wait. It will waste CPU cycles.
*
* usec Number of microseconds to sleep.
*/
int uSleep(unsigned long usec);

#endif
