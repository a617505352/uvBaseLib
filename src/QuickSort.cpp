#include "QuickSort.h"

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

	int leftSize, rightSize;
	int pos = partition(array, array_num);
	
	leftSize = pos;
	rightSize = array_num - leftSize - 1;
	Sort(array, leftSize);
	Sort(array + pos + 1, rightSize);
}

int CQuickSort::partition(int* data, int size)
{
	if (1 == size) {
		return 0;
	}

	int left = 0;
	int right = size - 1;
	int key = data[0];

	for (; left < right ;) {
		if (data[right] >= key) {
			right--;
		} else {
			for (; left < right;) {
				if (data[left] <= key) {
					left++;
				} else {
					int tmp = data[left];
					data[left] = data[right];
					data[right] = tmp;

					right--;
					break;
				}
			}
		}
	}
	data[0] = data[right];
	data[right] = key;

	return right;
}
