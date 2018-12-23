#ifndef _UV_LIB_SORT_H_
#define _UV_LIB_SORT_H_

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

class ISortBase
{
public:
	ISortBase();
	virtual ~ISortBase();

public:
	virtual void Sort(int* array, int array_num);
};

class CSortFactory
{
public:
	CSortFactory();
	~CSortFactory();

public:
	void SetType(sort_type_e type);
	ISortBase* GetObject(void);

private:
	ISortBase*	m_sort_obj;
	sort_type_e m_sort_type;
};

#endif
