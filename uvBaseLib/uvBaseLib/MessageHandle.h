#ifndef _MESSAGE_HANDLE_H_
#define _MESSAGE_HANDLE_H_

#include <deque>
#include <mutex>
#include <memory>
#include <thread>
#include <condition_variable>

class CMessageHandle;

typedef struct SigNode
{
	CMessageHandle* handle;
	long			session_id;
	int				message_type;
}SigNode;

class CMessageHandle
{
public:
	CMessageHandle();
	virtual ~CMessageHandle();

public:
	void Notify(CMessageHandle* handle, long session_id, int message_type);
	long GetID(void);
	void SetOwner(CMessageHandle* owner);

public:
	static void Looper(void);

public:
	virtual void handle_message(long session_id, int message_type);

private:
	void destroy(void);

protected:
	CMessageHandle*						m_owner;

private:
	static bool							m_is_closed;
	static long							m_session_id;
	static long							m_refrence_num;
	long								m_own_id;

	static std::mutex					m_ref_mtx;
	static std::mutex					m_msg_mtx;
	static std::condition_variable		m_msg_con;
	static std::deque<SigNode>			m_messages;

	std::shared_ptr<std::thread> m_message_loop_thread;
//	static std::thread					m_message_loop_thread;
};	

#endif
