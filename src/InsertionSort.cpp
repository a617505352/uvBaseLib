#include "InsertionSort.h"

CInsertionSort::CInsertionSort()
{

}

CInsertionSort::~CInsertionSort()
{

}

void CInsertionSort::Sort(int* array, int array_num)
{
	for (int i = 1; i < array_num; i++){
		int key = array[i];
		int j = i - 1;
		while (j>=0 && array[j] > key){
			array[j + 1] = array[j];
			j -= 1;
		}
		array[j + 1] = key;
	}

	return;
}
