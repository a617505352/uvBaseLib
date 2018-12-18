#include "BubbleSort.h"

CBubbleSort::CBubbleSort()
{

}

CBubbleSort::~CBubbleSort()
{

}

void CBubbleSort::Sort(int* array, int array_num)
{
	for (int num = 0; num < array_num; num++) {
		for (int idx = 0; idx < array_num - 1 - num; idx++) {
			if (array[idx] > array[idx + 1]) {
				int tmp = array[idx + 1];
				array[idx + 1] = array[idx];
				array[idx] = tmp;
			}
		}
	}
}
