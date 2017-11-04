#include <windows.h>
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
	CLivechannel* livechannel = new CLivechannel;
	livechannel->SetOwner(this);
	livechannel->Start();
}

void CManager::handle_message(long session_id, int message_type)
{
	printf("CManager: recv message:%d, session id:%d\n", message_type, session_id);
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
	CClient* client = new CClient;
	client->SetOwner(this);
	client->Start();
	Sleep(100);
}

void CLivechannel::handle_message(long session_id, int message_type)
{
	Notify(m_owner, GetID(), 20);

	is_closed = true;
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
	Notify(m_owner, GetID(), 30);
	return;
}

void CClient::handle_message(long session_id, int message_type)
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
