#ifndef _UV_LIB_HEAP_SORT_H_
#define _UV_LIB_HEAP_SORT_H_

#include "Sort.h"

/**
* ������a[1,...,n]
*
* ��ʼ���ѣ�������a[1...n]��������ѡ�
* �������ݣ���a[1]��a[n]������ʹa[n]��a[1...n]�е����ֵ��Ȼ��a[1...n-1]���µ���Ϊ���ѣ�
* ���ţ���a[1]��a[n-1]������ʹa[n-1]��a[1...n-1]�е����ֵ��
* Ȼ��a[1...n-2]���µ���Ϊ���ֵ��
* �������ƣ�ֱ���������ж�������ģ�
*
* ���ѣ����ڵ�Ԫ����󣬸��ڵ�Ԫ�ش����ӽڵ�Ԫ��
*
* ����ʵ�ֵ��������ʣ�
* 1������Ϊi�ڵ�����ӵ������� (2*i+1)
* 2������Ϊi�ڵ���Һ��ӵ������� (2*i+2)
* 3������Ϊi�ĸ����������� floor((i-1)/2)
*
* https://en.wikipedia.org/wiki/Heapsort
* http://www.cnblogs.com/skywang12345/p/3602162.html
* https://blog.csdn.net/u013384984/article/details/79496052
* 
* ʱ�临�Ӷȣ�O(N*lgN)
* �ռ临�Ӷ�: O(1)
*
* ���ڲ��ȶ��㷨
*
* �㷨�ȶ��ԣ� a[i] = a[j]�������a[i]��a[j]��˳�򲻱�
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
