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
* 最大堆：根节点元素最大，父节点元素大于子节点元素
*
* 数组实现的最大堆性质：
* 1、索引为i节点的左孩子的索引是 (2*i+1)
* 2、索引为i节点的右孩子的索引是 (2*i+2)
* 3、索引为i的父结点的索引是 floor((i-1)/2)
*
* https://en.wikipedia.org/wiki/Heapsort
* http://www.cnblogs.com/skywang12345/p/3602162.html
* https://blog.csdn.net/u013384984/article/details/79496052
* 
* 时间复杂度：O(N*lgN)
* 空间复杂度: O(1)
*
* 属于不稳定算法
*
* 算法稳定性： a[i] = a[j]，排序后，a[i]和a[j]的顺序不变
*
*/

class CHeapSort : public ISortBase
{
public:
	CHeapSort();
	virtual ~CHeapSort();

public:
	virtual void Sort(int* array, int array_num);

private:
	void adjustMaxHeap(int* array, int size);
};

#endif
