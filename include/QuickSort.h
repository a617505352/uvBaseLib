#ifndef _UV_LIB_QUICK_SORT_H_
#define _UV_LIB_QUICK_SORT_H_

#include <stdio.h>
#include "Sort.h"

/**
* https://en.wikipedia.org/wiki/Quicksort
*
* ��������
*
* ˼�룺��ѡһ������ߡ����������������й�һ��ɸ�ӣ��Ա�֤������ߵ�Ԫ�ض��������������ұߵ�Ԫ�ض���С������
*		��������������ͱ��ָ�Ϊ���������䣻�ٷֱ������������Ϳ����ˡ�
*
* 1��ѡȡһ���ؼ���(key)��Ϊ���ᣬһ��ȡ�����¼�ĵ�һ������
* 2��������������left = 0;right = N - 1;
* 3��right�Ӻ���ǰ��ֱ���ҵ�һ��С��key��ֵ����leftһֱ����ߣ�ֱ���ҵ�һ������key��ֵ��Ȼ�󽻻�����������
* 4���ظ���������һֱ�����ң�ֱ��left��right��������ʱ��key����right��λ�ü��ɡ�
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
