#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MergeSort.h"

CMergeSort::CMergeSort()
{
	m_data = NULL;
}

CMergeSort::~CMergeSort()
{
	if (m_data){
		free(m_data);
	}
}

void CMergeSort::Sort(int* array, int array_num)
{
	if (array_num == 1){
		return;
	} 
	m_data = (int*)malloc(array_num*sizeof(int));
	memset(m_data, 0, array_num);

	sort(array, 0, array_num - 1);
}

void CMergeSort::sort(int* array, int low, int high)
{
	if (high == low){
		return;
	}

	int mid = (low + high) / 2;
	sort(array, low, mid);
	sort(array, mid + 1, high);
	merge_lists(array, low, mid, high);
}

void CMergeSort::merge_lists(int* array, int low, int mid, int high)
{
	int down_length = mid - low + 1;
	int up_length = high - mid;

	int* down = array + low;
	int* up = array + mid + 1;

	int i, j;
	i = j = 0;
	int idx = 0;
	while (i<down_length && j<up_length){
		if (down[i] < up[j]){
			m_data[idx++] = down[i++];
		} else {
			m_data[idx++] = up[j++];
		}
	}

	if (j == up_length){
		for (; i < down_length;){
			m_data[idx++] = down[i++];
		}
	} else {
		for (; j < up_length;){
			m_data[idx++] = up[j++];
		}
	}

	for (int i = 0; i < high - low + 1; i++){
		array[low+i] = m_data[i];
	}
}
