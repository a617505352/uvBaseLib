#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "TESTMessagehandle.h"

CManager::CManager()
{
	is_closed = false;
}

CManager::~CManager()
{

}

void CManager::Start()
{
	live_channel = new CLivechannel;
	live_channel->SetOwner(this);
	live_channel->Start();
}

void CManager::onMessage(long session_id, int message_type)
{
	printf("CManager: recv message:%d, session id:%d\n", message_type, session_id);
	delete live_channel;
	live_channel = NULL;
}

/////////////////////////////////////////////////////////////////////////////////

CLivechannel::CLivechannel()
{
	is_closed = false;
}

CLivechannel::~CLivechannel()
{

}

void CLivechannel::Start()
{
	client = new CClient;
	client->SetOwner(this);
	client->Start();
}

void CLivechannel::onMessage(long session_id, int message_type)
{
	Notify(m_owner, GetID(), message_type+2);
	//delete client;
	//client = NULL;

	printf("CLivechannel: recv message:%d, session id:%d\n", message_type, session_id);
}

//////////////////////////////////////////////////////////////////////////////////////

CClient::CClient()
{

}

CClient::~CClient()
{

}

void CClient::Start()
{
	Notify(m_owner, GetID(), 20);
	Sleep(10);
	Notify(m_owner, GetID(), 21);
	return;
}

void CClient::onMessage(long session_id, int message_type)
{
	printf("CClient: recv message:%d, session id:%d\n", message_type, session_id);
}

/////////////////////////////////////////////////////////////////////////////////

#include "Configure.h"

#ifdef TEST_MESSAGE_HANDLE

int main()
{
	CManager* manger = new CManager;
	manger->Start();

	while (true)
	{
		char c;
		scanf("%c", &c);

		if (c == 'q' || c == 'Q'){
			break;
		}
	}

	if (manger){
		delete manger;
	}
	return 0;
}

#endif
