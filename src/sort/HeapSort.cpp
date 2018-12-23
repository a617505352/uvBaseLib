#include "HeapSort.h"

#define SWAP(a, b) \
	int tmp = a; \
	a = b; \
	b = tmp;

CHeapSort::CHeapSort()
{

}

CHeapSort::~CHeapSort()
{

}

void CHeapSort::Sort(int* array, int array_num)
{
	for (int i = 0; i < array_num; i++) {
		adjustMaxHeap(array, array_num - i);

		SWAP(array[0], array[array_num-1-i]);
	}
}

void CHeapSort::adjustMaxHeap(int* array, int size)
{
	int nodeIdx = size/2 -1;
	for (; nodeIdx >= 0; nodeIdx--) {
		if (array[nodeIdx] < array[2 * nodeIdx + 1]) {
			SWAP(array[nodeIdx], array[2 * nodeIdx + 1]);
		}

		if (array[nodeIdx] < array[2 * nodeIdx + 2] && (2 * nodeIdx + 2) < size) {
			SWAP(array[nodeIdx], array[2 * nodeIdx + 2]);
		}
	}

	return;
}
