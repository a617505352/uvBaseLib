#ifndef _TEST_SLIST_H_
#define _TEST_SLIST_H_

#include "slist.h"

class CTestSlist
{
public:
	CTestSlist();
	~CTestSlist();

public:
	void InsertTest(const int &value);
	void DeleteTest(const int &value);
	void DeleteAllTest(const int &value);
	void LookupTest(const int &value);
	void ReserveTest();
	void PrintTest();
	void ClearTest();

private:
	CSlist*	m_list;
};

#endif
