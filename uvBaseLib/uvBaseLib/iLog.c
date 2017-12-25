#include "iLog.h"

static log_handle_t	*g_log_handle = NULL;

static void pre_write_log(char *filename, long fileline, const log_print_type_e type, const char* format, const va_list varArgs);
static void write_log(const char* format, ...);
static const char* type_to_string(const log_print_type_e type);

log_handle_t* LogInit(char* filename)
{
	g_log_handle = (log_handle_t*)malloc(sizeof(log_handle_t));
	memset(g_log_handle, 0, sizeof(log_handle_t));

	g_log_handle->print_type = DEFAULT_LOG_PRINT_LEVEL;
	g_log_handle->save_type = DEFAULT_LOG_SAVE_TYPE;

	memcpy(g_log_handle->log_path, filename, LOG_MAX_FILE_PATH_LENGTH);
	g_log_handle->fd = fopen(filename, "wb+");

	return g_log_handle;
}

void LogUninit()
{
	if (g_log_handle) {
		if (g_log_handle->fd != NULL) {
			fclose(g_log_handle->fd);
			g_log_handle->fd = NULL;
		}

		free(g_log_handle);
		g_log_handle = NULL;
	}
}

void LogThreshold(log_print_type_e level)
{
	if (g_log_handle) {
		g_log_handle->print_type = level;
	}
}

void LogDebug(char *filename, long fileline, const char* format, ...)
{
	va_list varArgs;
	va_start(varArgs, format);
	pre_write_log(filename, fileline, ILOG_TYPE_DEBUG, format, varArgs);
	va_end(varArgs);
}

void LogInfo(char *filename, long fileline, const char* format, ...)
{
	va_list varArgs;
	va_start(varArgs, format);
	pre_write_log(filename, fileline, ILOG_TYPE_INFO, format, varArgs);
	va_end(varArgs);
}

void LogWarn(char *filename, long fileline, const char* format, ...)
{
	va_list varArgs;
	va_start(varArgs, format);
	pre_write_log(filename, fileline, ILOG_TYPE_WARN, format, varArgs);
	va_end(varArgs);
}

void LogError(char *filename, long fileline, const char* format, ...)
{
	va_list varArgs;
	va_start(varArgs, format);
	pre_write_log(filename, fileline, ILOG_TYPE_ERROR, format, varArgs);
	va_end(varArgs);
}

void LogFatal(char *filename, long fileline, const char* format, ...)
{
	va_list varArgs;
	va_start(varArgs, format);
	pre_write_log(filename, fileline, ILOG_TYPE_FATAL, format, varArgs);
	va_end(varArgs);
}

static void pre_write_log(char *filename, long fileline, const log_print_type_e type, const char* format, const va_list varArgs)
{
	if (type > g_log_handle->print_type) {
		return;
	}

	char log_message[MAX_LINE_SIZE] = { 0 };
#ifdef WIN32
	vsnprintf(log_message, sizeof(log_message), format, varArgs);
#else
	snprintf(log_message, sizeof(log_message), format, varArgs);
#endif

	char time_buf[DAFAULT_LINE_SIZE] = { 0 };
#ifdef WIN32
	SYSTEMTIME win_time;
	GetLocalTime(&win_time);
	_snprintf(time_buf, DAFAULT_LINE_SIZE, "[%02d:%02d:%02d.%03d %02d/%02d]",
		win_time.wHour, win_time.wMinute, win_time.wSecond, win_time.wMilliseconds, win_time.wMonth, win_time.wDay);
#else
	time_t timestamp;
	time(&timestamp);
	strftime(time_buf, sizeof(buffer), "%X %x", localtime(&timestamp));
#endif

	char source_buf[DAFAULT_LINE_SIZE] = { 0 };
#ifdef WIN32
	_snprintf(source_buf, sizeof(source_buf), "[%s:%ld]", filename, fileline);
#else
	snprintf(source_buf, sizeof(source_buf), "[%s:%ld]", pfilename, c_fileline);
#endif

	unsigned long	tid;
#if ( defined _WIN32 )
	tid = (unsigned long)GetCurrentThreadId();
#elif ( defined __unix ) || ( defined _AIX ) || ( defined __linux__ ) || ( defined __hpux )
#if ( defined _PTHREAD_H )
	tid = (unsigned long)pthread_self();
#endif
#endif

	write_log("%s%s[%u]%s%s%s", time_buf, type_to_string(type), tid, source_buf, log_message, LOG_NEWLINE);
}

void write_log(const char* format, ...)
{
	char buffer[MAX_LINE_SIZE + DAFAULT_LINE_SIZE * 2] = {0};

	va_list varArgs;
	va_start(varArgs, format);
#ifdef WIN32
	vsnprintf(buffer, sizeof(buffer), format, varArgs);
#else
	vsnprintf(buffer, sizeof(buffer), format, varArgs);
#endif
	va_end(varArgs);

	int length = strlen(buffer);

	if (g_log_handle) {
		if (g_log_handle->fd != NULL) {
			fwrite(buffer, length, 1, g_log_handle->fd);
			fflush(g_log_handle->fd);
		}
	}
}

const char* type_to_string(const log_print_type_e type) {
	switch (type) {
	case ILOG_TYPE_FATAL:
		return "[FATAL]";
	case ILOG_TYPE_ERROR:
		return "[ERROR]";
	case ILOG_TYPE_WARN:
		return "[WARN]";
	case ILOG_TYPE_INFO:
		return "[INFO]";
	case ILOG_TYPE_DEBUG:
		return "[DEBUG]";
	default:
		break;
	}
	return "[UNKWN]";
}
