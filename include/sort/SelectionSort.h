#ifndef _UV_LIB_SELECTION_SORT_H_
#define _UV_LIB_SELECTION_SORT_H_

#include "Sort.h"

/**
* 选择排序：
* 
* 1、初始时在序列中找到最小元素，放到序列的起始位置作为已排序序列；
* 2、再从剩余未排序元素中继续寻找最小元素，放到已排序序列的末尾；
* 3、重复上述步骤；
*
* https://en.wikipedia.org/wiki/Selection_sort 
*
* 时间复杂度：O(n^2)
* 空间复杂度：O(1)
*/

class CSelectionSort : public ISortBase
{
public:
	CSelectionSort();
	virtual ~CSelectionSort();

public:
	virtual void Sort(int* array, int array_num);

};

#endif
