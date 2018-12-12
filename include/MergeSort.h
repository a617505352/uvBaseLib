#ifndef _UV_LIB_MERGER_SORT_H_
#define _UV_LIB_MERGER_SORT_H_

/**
* create by chenliang,2018.3.7
* �鲢�����㷨:
*	�ݹ�ķֳ�����������Ȼ��ϲ�;
*
* MergeSort A[1,...,N]:
*	1. if N=1 done
*	2. recursively sort A[1,...,N/2] and A[N/2+1,...,N]
*	3. merge 2 sorted lits
*
* ʱ�临�Ӷȣ�O(N*lgN)
* �ռ临�Ӷȣ�O(N)
*/

#include "Sort.h"

class CMergeSort : public ISortBase
{
public:
	CMergeSort();
	virtual ~CMergeSort();

public:
	virtual void Sort(int* array, int array_num);

private:
	void sort(int* array, int low, int high);
	void merge_lists(int* array, int low, int mid, int high);

private:
	int*	m_data;
};

#endif
