#ifndef _UV_LIB_QUICK_SORT_H_
#define _UV_LIB_QUICK_SORT_H_

#include <stdio.h>
#include "Sort.h"

/**
* https://en.wikipedia.org/wiki/Quicksort
*
* 升序排序
*
* 思想：先选一个“标尺”，用它把整个队列过一遍筛子，以保证：其左边的元素都不大于它，其右边的元素都不小于它；
*		这样，排序问题就被分割为两个子区间；再分别对子区间排序就可以了。
*
* 1、选取一个关键字(key)作为枢轴，一般取整组记录的第一个数；
* 2、设置两个变量left = 0;right = N - 1;
* 3、right从后至前，直至找到一个小于key的值，从left一直向后走，直到找到一个大于key的值，然后交换这两个数。
* 4、重复第三步，一直往后找，直到left和right相遇，这时将key放置right的位置即可。
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
