#ifndef _UV_LIB_SELECTION_SORT_H_
#define _UV_LIB_SELECTION_SORT_H_

#include "Sort.h"

/**
* ѡ������
* 
* 1����ʼʱ���������ҵ���СԪ�أ��ŵ����е���ʼλ����Ϊ���������У�
* 2���ٴ�ʣ��δ����Ԫ���м���Ѱ����СԪ�أ��ŵ����������е�ĩβ��
* 3���ظ��������裻
*
* https://en.wikipedia.org/wiki/Selection_sort 
*
* ʱ�临�Ӷȣ�O(n^2)
* �ռ临�Ӷȣ�O(1)
*/

class CSelectionSort : public ISortBase
{
public:
	CSelectionSort();
	virtual ~CSelectionSort();

public:
	virtual void Sort(int* array, int array_num);

};

#endif
