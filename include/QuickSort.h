#ifndef _UV_LIB_QUICK_SORT_H_
#define _UV_LIB_QUICK_SORT_H_

#include "Sort.h"

/**
* https://en.wikipedia.org/wiki/Quicksort
*
* ��������
*
* ˼�룺��ѡһ������ߡ����������������й�һ��ɸ�ӣ��Ա�֤������ߵ�Ԫ�ض��������������ұߵ�Ԫ�ض���С������
*		��������������ͱ��ָ�Ϊ���������䣻�ٷֱ������������Ϳ����ˡ�
*
* ʱ�临�Ӷȣ�O(N*lgN)
* �ռ临�Ӷȣ�O(N)
*
* ���÷��η�(Devide and Conquer)
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
