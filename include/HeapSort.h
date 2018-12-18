#ifndef _UV_LIB_HEAP_SORT_H_
#define _UV_LIB_HEAP_SORT_H_

#include "Sort.h"

/**
* 堆排序：a[1,...,n]
*
* 初始化堆：将数列a[1...n]构造成最大堆。
* 交换数据：将a[1]和a[n]交换，使a[n]是a[1...n]中的最大值，然后将a[1...n-1]重新调整为最大堆；
* 接着，将a[1]和a[n-1]交换，使a[n-1]是a[1...n-1]中的最大值；
* 然后将a[1...n-2]重新调整为最大值；
* 依次类推，直到整个数列都是有序的；
*
* https://en.wikipedia.org/wiki/Heapsort
* http://www.cnblogs.com/skywang12345/p/3602162.html
* https://blog.csdn.net/u013384984/article/details/79496052
* 
*/

class CHeapSort : public ISortBase
{
public:
	CHeapSort();
	virtual ~CHeapSort();

public:
	virtual void Sort(int* array, int array_num);
};

#endif
