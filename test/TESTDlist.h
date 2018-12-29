#ifndef _TEST_DLIST_H_
#define _TEST_DLIST_H_

#include "dlist.h"

class CTestDlist
{
public:
	CTestDlist();
	~CTestDlist();

public:
	void InsertTest(const int &value);
	void DeleteTest(const int &value);
	void DeleteAllTest(const int &value);
	void ReserveTest();
	void PrintTest();
	void ClearTest();

	Node* LookupTest(const int &value);
	Node* HeadTest();
	Node* TailTest();

private:
	CDlist*	m_list;
};

#endif
