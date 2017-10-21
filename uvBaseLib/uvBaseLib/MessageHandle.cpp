#include <windows.h>
#include "MessageHandle.h"
#include "LOG.h"


bool CMessageHandle::m_is_closed  = false;
long CMessageHandle::m_session_id = 10000;
long CMessageHandle::m_refrence_num = 0;

std::mutex					CMessageHandle::m_ref_mtx;
std::mutex					CMessageHandle::m_msg_mtx; 
std::condition_variable		CMessageHandle::m_msg_con;
std::deque<SigNode>			CMessageHandle::m_messages;

			CMessageHandle::m_message_loop_thread(&CMessageHandle::Looper);

CMessageHandle::CMessageHandle()
{
	InterlockedIncrement(&m_refrence_num);
	m_own_id = InterlockedIncrement(&m_session_id);
	m_owner = NULL;

	m_message_loop_thread.reset(&CMessageHandle::Looper);
}

CMessageHandle::~CMessageHandle()
{
	std::unique_lock<std::mutex> lock(m_msg_mtx);
	if (!InterlockedDecrement(&m_refrence_num)) {
		lock.unlock();
		destroy();
	} else {
		lock.unlock();
	}
}

void CMessageHandle::Notify(CMessageHandle* handle, long session_id, int message_type)
{
	SigNode sig_node = { 0 };
	sig_node.handle = handle;
	sig_node.message_type = message_type;
	sig_node.session_id = session_id;

	std::unique_lock<std::mutex> lock(m_msg_mtx);
	m_messages.push_back(sig_node);
	m_msg_con.notify_one();
	lock.unlock();

	return;
}

long CMessageHandle::GetID(void)
{
	return m_own_id;
}

void CMessageHandle::Looper()
{
	while (true) {
		if (m_is_closed) {
			break;
		}

		//SigNode sig_node = { 0 };
		//std::unique_lock<std::mutex> lock(m_msg_mtx);
		//if (m_messages.empty()) {
		//	m_msg_con.wait(lock);
		//	if (m_is_closed) {
		//		break;
		//	}
		//}
		//sig_node = m_messages.front();
		//m_messages.pop_front();
		//lock.unlock();

		//sig_node.handle->handle_message(sig_node.session_id, sig_node.message_type);
	}
	return;
}

void CMessageHandle::SetOwner(CMessageHandle* owner)
{
	m_owner = owner;
}

void CMessageHandle::handle_message(long session_id, int message_type)
{
	return;
}

void CMessageHandle::destroy(void)
{
	m_is_closed = true;
	std::unique_lock<std::mutex> lock(m_msg_mtx);
	m_msg_con.notify_one();

	while (m_messages.size() > 0) {
		m_messages.pop_front();
	}
	lock.unlock();

	m_message_loop_thread.join();
	return;
}