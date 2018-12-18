#ifndef _UV_LIB_BUBBLE_SORT_H_
#define _UV_LIB_BUBBLE_SORT_H_

#include "Sort.h"

/**
* ð������
* 1����ǰ���󣬱Ƚ��������������������ƶ���С����ǰ�ƶ���ֱ��β��;
* 2���ظ���һ����ֱ�������е������ƶ���һ�飻
* 
* https://en.wikipedia.org/wiki/Bubble_sort
*
* ʱ�临�Ӷȣ�O(n^2)
* �ռ临�Ӷȣ�O(1)
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
