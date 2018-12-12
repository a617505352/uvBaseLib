#include "TESTSort.h"
#include "Sort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

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
	int array[] = {3,7,4,9,5,2,6,1};
	int size = sizeof(array) / sizeof(int);

	CTestSort *t = new CTestSort;
	t->SetType(sort_type_merge);
	t->SortTest(array, size);

	for (int i = 0; i < size;i++)
	{
		printf(" %d ", array[i]);
	}
	printf("\n");

	system("pause");

	return 0;
}

#endif