#include "SelectionSort.h"

CSelectionSort::CSelectionSort()
{

}

CSelectionSort::~CSelectionSort()
{

}

void CSelectionSort::Sort(int* array, int array_num)
{
	int idx = 0;
	int max = 0;
	for (int j = 0; j < array_num; j++) {
		for (int i = 0; i < array_num - j; i++) {
			if (array[i] > max) {
				max = array[i];
				idx = i;
			}
		}

		array[idx] = array[array_num - 1 - j];
		array[array_num - 1 - j] = max;

		max = 0;
		idx = 0;
	}
}
