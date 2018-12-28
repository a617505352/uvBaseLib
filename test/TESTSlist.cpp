#include "TESTSlist.h"

CTestSlist::CTestSlist()
{
	m_list = new CSlist;
}

CTestSlist::~CTestSlist()
{
	if (m_list != NULL) {
		delete m_list;
		m_list = NULL;
	}
}

void CTestSlist::InsertTest(const int &value)
{
	m_list->Insert(value);
}

void CTestSlist::DeleteTest(const int &value)
{
	m_list->DeleteFir(value);
}

void CTestSlist::DeleteAllTest(const int &value)
{
	m_list->DeleteAll(value);
}

void CTestSlist::LookupTest(const int &value)
{
	m_list->LookUp(value);
}

void CTestSlist::ReserveTest()
{
	m_list->Reserve();
}

void CTestSlist::PrintTest()
{
	m_list->Print();
}

void CTestSlist::ClearTest()
{
	m_list->Clear();
}

//////////////////////////////////////

#include "Configure.h"

#ifdef TEST_SLIST

int main()
{
	CTestSlist test;

	int array1[] = { 54, 38, 96, 23, 15, 72, 60, 45, 83 };
	int size1 = sizeof(array1) / sizeof(int);
	for (int i = 0; i < size1;i++){
		test.InsertTest(array1[i]);
	}
	test.PrintTest();
	test.ReserveTest();
	test.PrintTest();
	test.DeleteTest(45);
	test.PrintTest();
	test.InsertTest(7);
	test.PrintTest();
	test.InsertTest(105);
	test.PrintTest();
	test.ClearTest();
	test.PrintTest();

	int array2[] = { 3, 7, 4, 9, 5, 2, 6, 1 };
	int size2 = sizeof(array2) / sizeof(int);
	for (int i = 0; i < size2; i++) {
		test.InsertTest(array2[i]);
	}
	test.PrintTest();
	test.ReserveTest();
	test.PrintTest();
	test.DeleteTest(5);
	test.PrintTest();
	test.ClearTest();

	int array3[] = { 4, 1, 7, 6, 9, 2, 8, 4, 0, 3, 5 };
	int size3 = sizeof(array3) / sizeof(int);
	for (int i = 0; i < size3; i++) {
		test.InsertTest(array3[i]);
	}
	test.PrintTest();
	test.ReserveTest();
	test.PrintTest();
	test.DeleteAllTest(4);
	test.PrintTest();

	return 0;
}

#endif