#include "TESTiLog.h"

#include <string>
#include <random>

extern "C"{
#include "iLog.h"
}

CTestiLog::CTestiLog()
{
	m_is_closed = false;
}

CTestiLog::~CTestiLog()
{
	m_is_closed = true;

	for (int i = 0; i < TEST_THREADS_NUMS; i++){
		if (m_threads[i] && m_threads[i]->joinable())
			m_threads[i]->join();
	}
}

void CTestiLog::Start()
{
	for (int i = 0; i < TEST_THREADS_NUMS; i++){
		if (m_threads[i] && m_threads[i]->joinable())
			m_threads[i]->join();

		m_threads[i].reset(new std::thread(&CTestiLog::looper_thread, this, i));
	}
}

void CTestiLog::looper_thread(int id)
{
	while (true)
	{
		if (m_is_closed){
			break;
		}

		std::random_device rd;
		int key = rd() % 6 + 1;
		double nums = rd() / 30;
		iLogDebug("id:%d, %s, %f.", id, key_to_string(key), nums);
		iLogInfo("id:%d, %s, %f.", id, key_to_string(key), nums);
		iLogWarn("id:%d, %s, %f.", id, key_to_string(key), nums);
		iLogError("id:%d, %s, %f.", id, key_to_string(key), nums);
	}
}

char* CTestiLog::key_to_string(int key)
{
	switch (key)
	{
	case 1:
		return "It takes a strong man to save himself, and a great man to save another.";
	case 2:
		return "Get busy living, Or get busy dying.";
	case 3:
		return "Hope is a good thing, maybe the best of things, and no good thing ever dies.";
	case 4:
		return "some birds aren't meant to be caged, that's all. Their feathers are just too bright...";
	case 5:
		return "Fear can hold you prisoner,hope can set you free.";
	case 6:
		return "I hope the Pacific is as blue as I dreamed it is.";
		break;
	default:
		return "zihuatanejo";
	}
}

/////////////////////////////////////////////////////////////////////////////////

#include "logging.h"

static void log_callback(int level, const char * szFmt, va_list varg)
{
	char line[1024] = { 0 };
	vsnprintf(line, sizeof(line), szFmt, varg);

	switch (level) {
	case ILOG_TYPE_DEBUG:
		Log::Debug("%s", line);
		break;
	case ILOG_TYPE_INFO:
		Log::Info("%s", line);
		break;
	case ILOG_TYPE_WARN:
		Log::Warn("%s", line);
		break;
	case ILOG_TYPE_ERROR:
		Log::Error("%s", line);
		break;
	case ILOG_TYPE_FATAL:
		Log::Fatal("%s", line);
		break;
	default:
		Log::Info("%s", line);
		break;
	}
	return;
}

#define LOG_CALLBACK_TEST 1

int main(int argc, char* argv)
{
	log_handle_t *g = NULL;
	g = LogInit();
	if (g == NULL) {
		printf("create iLog3 Handle errno, errno number=[%d]\n", errno);
		return -1;
	}
	LogThreshold(ILOG_TYPE_DEBUG);

#ifdef LOG_CALLBACK_TEST
	LogSetCallback(log_callback);

	std::string url = "./iLogDemo.log";
	Log::Initialise(url);
	Log::SetThreshold(Log::LOG_TYPE_DEBUG);
#else
	LogSetPath("iLogTest.log");
#endif

	CTestiLog* log = new CTestiLog;
	log->Start();

	while (true)
	{
		char c;
		scanf("%c", &c);

		if (c == 'q' || c == 'Q'){
			break;
		}
	}

	if (log){
		delete log;
	}

#ifdef LOG_CALLBACK_TEST
	Log::Finalise();
#endif

	LogUninit();
	printf("destroy iLog handle.\n");

	return 0;
}
