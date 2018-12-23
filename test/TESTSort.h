#ifndef _TEST_SORT_H_
#define _TEST_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Sort.h>

class CTestSort
{
public:
	CTestSort();
	~CTestSort();

public:
	void SortTest(int* data, int size);
	void SetType(sort_type_e type);

private:
	sort_type_e m_type;
};

#endif