#include "QuickSort.h"
#include <stdio.h>

CQuickSort::CQuickSort()
{

}

CQuickSort::~CQuickSort()
{

}

void CQuickSort::Sort(int* array, int array_num)
{
	if (1 == array_num || array_num == 0) {
		return;
	}

	int upSize, downSize;
	int pos = partition(array, array_num);
	
	upSize = pos;
	downSize = array_num - upSize - 1;
	Sort(array, upSize);
	Sort(array + pos + 1, downSize);
}

int CQuickSort::partition(int* data, int size)
{
	if (1 == size) {
		return 0;
	}

	int i = 1;
	int j = size - 1;
	int key = data[0];
	for (; i != j ;) {
		if (data[j] > key) {
			j--;
		} else {
			for (; i != j;) {
				if (data[i] < key) {
					i++;
				} else {
					int tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;

					j--;
					break;
				}
			}
		}
	}

	data[0] = data[i];
	data[i] = key;

	for (int idx = 0; idx <= size - 1; idx++) {
		printf(" %d ", data[idx]);
	}
	printf("i:%d\n", i);

	return i;
}
