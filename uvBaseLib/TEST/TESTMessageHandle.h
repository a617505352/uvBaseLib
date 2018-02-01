#ifndef _TEST_MESSAGE_HANDLE_H_
#define _TEST_MESSAGE_HANDLE_H_

#include "MessageHandle.h"

class CLivechannel;
class CClient;

class CManager: public CMessageHandle
{
public:
	CManager();
	~CManager();

public:
	void Start();

public:
	void onMessage(long session_id, int message_type);

private:
	bool			is_closed;
	CLivechannel*	live_channel;
};

class CLivechannel : public CMessageHandle
{
public:
	CLivechannel();
	~CLivechannel();

public:
	void Start();

public:
	void onMessage(long session_id, int message_type);

private:
	bool is_closed;
	CClient* client;
};

class CClient : public CMessageHandle
{
public:
	CClient();
	~CClient();

public:
	void Start();

public:
	void onMessage(long session_id, int message_type);

};

#endif
