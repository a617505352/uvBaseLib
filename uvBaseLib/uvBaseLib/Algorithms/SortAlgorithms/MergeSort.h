#ifndef _UV_LIB_MERGER_SORT_H_
#define _UV_LIB_MERGER_SORT_H_

#include "Sort.h"

class CMergeSort : public ISortBase
{
public:
	CMergeSort();
	virtual ~CMergeSort();

public:
	virtual void Sort(int* array, int array_num);

};

#endif
