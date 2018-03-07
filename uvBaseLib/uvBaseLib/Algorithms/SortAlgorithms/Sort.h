#ifndef _UV_LIB_SORT_H_
#define _UV_LIB_SORT_H_

/**
* create by chenliang, 2018.3.7
* base class for Sort
*/

class ISortBase
{
public:
	ISortBase();
	virtual ~ISortBase();

public:
	virtual void Sort(int* array, int array_num);
};

#endif
