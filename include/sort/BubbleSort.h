#ifndef _UV_LIB_BUBBLE_SORT_H_
#define _UV_LIB_BUBBLE_SORT_H_

#include "Sort.h"

/**
* 冒泡排序：
* 1、从前往后，比较相邻数，将大数往后移动，小数向前移动，直到尾部;
* 2、重复第一步，直到将所有的数都移动了一遍；
* 
* https://en.wikipedia.org/wiki/Bubble_sort
*
* 时间复杂度：O(n^2)
* 空间复杂度：O(1)
*
*/

class CBubbleSort : public ISortBase
{
public:
	CBubbleSort();
	virtual ~CBubbleSort();

public:
	virtual void Sort(int* array, int array_num);
};

#endif
