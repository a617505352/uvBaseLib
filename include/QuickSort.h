#ifndef _UV_LIB_QUICK_SORT_H_
#define _UV_LIB_QUICK_SORT_H_

#include "Sort.h"

/**
* https://en.wikipedia.org/wiki/Quicksort
*
* 升序排序
*
* 思想：先选一个“标尺”，用它把整个队列过一遍筛子，以保证：其左边的元素都不大于它，其右边的元素都不小于它；
*		这样，排序问题就被分割为两个子区间；再分别对子区间排序就可以了。
*
* 时间复杂度：O(N*lgN)
* 空间复杂度：O(N)
*
* 采用分治法(Devide and Conquer)
*/

class CQuickSort : public ISortBase
{
public:
	CQuickSort();
	virtual ~CQuickSort();

public:
	virtual void Sort(int* array, int array_num);

private:
	int partition(int* data, int size);

};

#endif
