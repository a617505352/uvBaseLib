#ifndef _TEST_LOG_H_
#define _TEST_LOG_H_

#include <memory>
#include <thread>

#define TEST_THREADS_NUMS 10

class CTestLog
{
public:
	CTestLog();
	~CTestLog();

	void Start();

private:
	void looper_thread(int id);

	char* key_to_string(int key);

private:
	bool m_is_closed;
	std::shared_ptr<std::thread>	m_threads[TEST_THREADS_NUMS];
};

#endif
