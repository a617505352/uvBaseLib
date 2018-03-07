#ifndef _UV_LIB_INSERTION_SORT_H_
#define _UV_LIB_INSERTION_SORT_H_

/**
* create by chenliang,2018.3.7 
* ���������㷨:
*	����ÿһ������һ���������ݰ����С���뵽�Ѿ�����������е��ʵ�λ�ã�ֱ��ȫ���������;
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
* ʱ�临�Ӷȣ�O(n2)
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
