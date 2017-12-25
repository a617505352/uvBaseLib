#ifndef _ILOG_H_
#define _ILOG_H_

/**
* �������������޳�û������������
*��������������    ����
*�����������ߩ��������ߩ�
*��������������������  �� ��
*��������      ������  ��
*������������������������
*������������������������
*���������������ߡ�������
*����������������	   ��
*������������������������
*������������������������������������������
*������������������������
*��������������������
*����������������������������������������
*�������������� �� ����������
*������������ ��������     �ǩ�
*������������ ����������   ����
*���������������������ש�����
*���������������ϩ�  ���ϩ�
*���������������ߩ�  ���ߩ�
*
* Create by chen, 2017/12/25
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#if ( defined _WIN32 )
#include <windows.h>
#include <share.h>
#include <io.h>
#include <fcntl.h>
#elif ( defined __unix ) || ( defined _AIX ) || ( defined __linux__ ) || ( defined __hpux )
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <syslog.h>
#include <pthread.h>
#endif

#if ( defined _WIN32 )
#define LOG_NEWLINE		"\r\n"
#define LOG_NEWLINE_LEN		2
#elif ( defined __unix ) || ( defined _AIX ) || ( defined __linux__ ) || ( defined __hpux )
#define LOG_NEWLINE		"\n"
#define LOG_NEWLINE_LEN		1
#endif

typedef enum log_save_type{
	ILOG_SAVE_UNKNOW = 0,
	ILOG_SAVE_FILE,
	ILOG_SAVE_CALLBACK,
}log_save_type_e;

typedef enum log_print_type {
	ILOG_TYPE_FATAL,
	ILOG_TYPE_ERROR,
	ILOG_TYPE_WARN,
	ILOG_TYPE_INFO,
	ILOG_TYPE_DEBUG
}log_print_type_e;


#define DAFAULT_LINE_SIZE	64
#define LOG_MAX_FILE_PATH_LENGTH 1024
#define MAX_LINE_SIZE LOG_MAX_FILE_PATH_LENGTH
#define DEFAULT_LOG_PRINT_LEVEL	ILOG_TYPE_INFO
#define DEFAULT_LOG_SAVE_TYPE	ILOG_SAVE_FILE


typedef struct log_handle{

	log_save_type_e		save_type;
	log_print_type_e	print_type;
	char				log_path[LOG_MAX_FILE_PATH_LENGTH];

	FILE*				fd;

}log_handle_t;

//////////////////////////////////////////////////////////////////////////////////////

log_handle_t* LogInit(char* filename);

void LogUninit();

void LogThreshold(log_print_type_e level);

void LogDebug(char *filename, long fileline, const char* format, ...);

void LogInfo(char *filename, long fileline, const char* format, ...);

void LogWarn(char *filename, long fileline, const char* format, ...);

void LogError(char *filename, long fileline, const char* format, ...);

void LogFatal(char *filename, long fileline, const char* format, ...);

/////////////////////////////////////////////////////////////////////////////////////

#define iLogDebug( ... )		LogDebug( __FILE__ , __LINE__ , ##__VA_ARGS__ );
#define iLogInfo( ... )			LogInfo( __FILE__ , __LINE__ , ##__VA_ARGS__ );
#define iLogWarn( ... )			LogWarn( __FILE__ , __LINE__ , ##__VA_ARGS__ );
#define iLogError( ... )		LogError( __FILE__ , __LINE__ , ##__VA_ARGS__ );
#define iLogFata( ... )		    LogFatal( __FILE__ , __LINE__ , ##__VA_ARGS__ );

#endif