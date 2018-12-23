#include "Sort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"

ISortBase::ISortBase()
{

}

ISortBase::~ISortBase()
{

}

void ISortBase::Sort(int* array, int array_num)
{
	return;
}

////////////////////////////////////////////////

CSortFactory::CSortFactory()
{
	m_sort_type = sort_type_unknow;
	m_sort_obj  = NULL;
}

CSortFactory::~CSortFactory()
{
	if (m_sort_obj != NULL){
		delete m_sort_obj;
		m_sort_obj = NULL;
	}
	m_sort_type = sort_type_unknow;
}

void CSortFactory::SetType(sort_type_e type)
{
	m_sort_type = type;
}

ISortBase* CSortFactory::GetObject(void)
{
	if (m_sort_obj != NULL){
		return m_sort_obj;
	}

	switch (m_sort_type) {
	case sort_type_insertion:
		m_sort_obj = new CInsertionSort;
		break;
	case sort_type_bubble:
		m_sort_obj = new CBubbleSort;
		break;
	case sort_type_heap:
		m_sort_obj = new CHeapSort;
		break;
	case sort_type_merge:
		m_sort_obj = new CMergeSort;
		break;
	case sort_type_selection:
		m_sort_obj = new CSelectionSort;
		break;
	case sort_type_quick:
		m_sort_obj = new CQuickSort;
		break;
	default:
		m_sort_obj = new CQuickSort;
		break;
	}

	return m_sort_obj;
}
