#ifdef WIN32
#include <windows.h>
#else

#endif
#include "MessageHandle.h"


long		CMessageHandle::m_session_id = 10000;
long		CMessageHandle::m_refrence_num = 0;
std::mutex	CMessageHandle::m_refrence_mtx;
CMessageThread* CMessageHandle::m_message_thread = NULL;

CMessageHandle::CMessageHandle()
{
	m_owner = NULL;

#ifdef WIN32
	m_own_id = InterlockedIncrement(&m_session_id);
#else
	m_own_id = __sync_fetch_and_add(&m_session_id, 1);
#endif

	std::unique_lock<std::mutex> ref_lock(m_refrence_mtx);
	m_refrence_num++;
	if (m_message_thread == NULL){
		m_message_thread = new CMessageThread;
	}
	ref_lock.unlock();
}

CMessageHandle::~CMessageHandle()
{
	std::unique_lock<std::mutex> ref_lock(m_refrence_mtx);
	m_refrence_num--;
	if (m_refrence_num == 0 && m_message_thread != NULL){
		m_message_thread->Close();
		m_message_thread = NULL;
	}
	ref_lock.unlock();
}

void CMessageHandle::Notify(CMessageHandle* handle, long session_id, int message_type)
{
	if (m_message_thread){
		m_message_thread->Enqueue(handle, session_id, message_type);
	}
	return;
}

long CMessageHandle::GetID(void)
{
	return m_own_id;
}

void CMessageHandle::SetOwner(CMessageHandle* owner)
{
	m_owner = owner;
}

void CMessageHandle::handle_message(long session_id, int message_type)
{
	return;
}
