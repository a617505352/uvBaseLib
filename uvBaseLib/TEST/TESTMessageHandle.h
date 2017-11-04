#ifndef _TEST_MESSAGE_HANDLE_H_
#define _TEST_MESSAGE_HANDLE_H_

#include "MessageHandle.h"

class CManager: public CMessageHandle
{
public:
	CManager();
	~CManager();

public:
	void Start();

public:
	void handle_message(long session_id, int message_type);

private:
	bool is_closed;

};

class CLivechannel : public CMessageHandle
{
public:
	CLivechannel();
	~CLivechannel();

public:
	void Start();

public:
	void handle_message(long session_id, int message_type);

private:
	bool is_closed;

};

class CClient : public CMessageHandle
{
public:
	CClient();
	~CClient();

public:
	void Start();

public:
	void handle_message(long session_id, int message_type);

};

#endif
