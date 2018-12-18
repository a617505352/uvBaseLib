#include "TESTSort.h"
#include "Sort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"

CTestSort::CTestSort()
{
	m_type = sort_type_unknow;
}

CTestSort::~CTestSort()
{

}

void CTestSort::SetType(sort_type_e type)
{
	m_type = type;
}

void CTestSort::SortTest(int* data, int size)
{
	ISortBase* sort = NULL;

	switch (m_type) {
	case sort_type_insertion:
		sort = new CInsertionSort;
		sort->Sort(data, size);
		break;
	case sort_type_bubble:
		sort = new CBubbleSort;
		sort->Sort(data, size);
		break;
	case sort_type_heap:
		break;
	case sort_type_merge:
		sort = new CMergeSort;
		sort->Sort(data, size);
		break;
	case sort_type_selection:
		break;
	case sort_type_quick:
		sort = new CQuickSort;
		sort->Sort(data, size);
		break;
	default:
		break;
	}

	delete sort;
}

///////////////////////////////////////////////////////////////

#include "Configure.h"

#ifdef  TEST_SORT_ALGORITHMS

int main()
{
	int array1[] = { 54, 38, 96, 23, 15, 72, 60, 45, 83 };//{ 3, 7, 4, 9, 5, 2, 6, 1 };//
	int size1 = sizeof(array1) / sizeof(int);

	int array2[] = { 3, 7, 4, 9, 5, 2, 6, 1 };
	int size2 = sizeof(array2) / sizeof(int);

	int array3[] = { 4,1,7,6,9,2,8,4,0,3,5 };
	int size3 = sizeof(array3) / sizeof(int);

	CTestSort *t = new CTestSort;
	t->SetType(sort_type_bubble);
	t->SortTest(array1, size1);
	for (int i = 0; i < size1;i++)
	{
		printf(" %d ", array1[i]);
	}
	printf("\n");

	t->SortTest(array2, size2);
	for (int i = 0; i < size2; i++)
	{
		printf(" %d ", array2[i]);
	}
	printf("\n");

	t->SortTest(array3, size3);
	for (int i = 0; i < size3; i++)
	{
		printf(" %d ", array3[i]);
	}
	printf("\n");

	system("pause");

	return 0;
}

#endif