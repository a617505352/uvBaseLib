#ifndef _TEST_SORT_H_
#define _TEST_SORT_H_

#include <stdio.h>
#include <stdlib.h>

typedef enum sort_type{
	sort_type_unknow = 0,
	sort_type_insertion,
	sort_type_bubble,
	sort_type_heap,
	sort_type_merge,
	sort_type_selection,
	sort_type_quick,
	sort_type_max,
} sort_type_e;

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