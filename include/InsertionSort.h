#ifndef _UV_LIB_INSERTION_SORT_H_
#define _UV_LIB_INSERTION_SORT_H_

/**
* create by chenliang,2018.3.7 
* 插入排序算法:
*	就是每一步都将一个待排数据按其大小插入到已经排序的数据中的适当位置，直到全部插入完毕;
*
* InsertionSort A[1,...,n]:
*	for i <- 2 to n
*		key <- A[i]
*		j <- i-1
*		while j>0 and A[j]>key
*			A[j+1] <- A[j]
*			j <- j-1
*		end while
*		A[j+1] <- key
*	end for
*	
* 时间复杂度：O(n2)
*/

#include "Sort.h"

class CInsertionSort : public ISortBase
{
public:
	CInsertionSort();
	virtual ~CInsertionSort();

public:
	virtual void Sort(int* array, int array_num);

};

#endif
