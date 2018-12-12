#include "TESTLog.h"
#include "LOG.h"

#include <string>
#include <random>

CTestLog::CTestLog()
{
	m_is_closed = false;
}

CTestLog::~CTestLog()
{
	m_is_closed = true;

	for (int i = 0; i < TEST_THREADS_NUMS; i++){
		if (m_threads[i] && m_threads[i]->joinable())
			m_threads[i]->join();
	}
}

void CTestLog::Start()
{
	for (int i = 0; i < TEST_THREADS_NUMS; i++){
		if (m_threads[i] && m_threads[i]->joinable())
			m_threads[i]->join();

		m_threads[i].reset(new std::thread(&CTestLog::looper_thread, this, i));
	}
}

void CTestLog::looper_thread(int id)
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

char* CTestLog::key_to_string(int key)
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

#include "Configure.h"

#ifdef TEST_LOG

int main(int argc, char* argv)
{
	LOG		*g = NULL;
	g = CreateLogHandleG();
	if (g == NULL) {
		printf("create iLog3 Handle errno, errno number=[%d]\n", errno);
		return -1;
	}
	SetLogOutputG(LOG_OUTPUT_FILE, "./test.log", LOG_NO_OUTPUTFUNC);
	SetLogLevelG(LOG_LEVEL_INFO);
	SetLogStylesG(LOG_STYLE_DEFAULT, LOG_NO_STYLEFUNC);

	CTestLog* log = new CTestLog;
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

	DestroyLogHandleG();
	printf("destroy iLog3 handle.\n");

	return 0;
}

#endif
