#include "TESTDlist.h"

CTestDlist::CTestDlist()
{
	m_list = new CDlist;
}

CTestDlist::~CTestDlist()
{
	if (m_list != NULL) {
		delete m_list;
		m_list = NULL;
	}
}

void CTestDlist::InsertTest(const int &value)
{
	m_list->Insert(value);
}

void CTestDlist::DeleteTest(const int &value)
{
	m_list->DeleteFirst(value);
}

void CTestDlist::DeleteAllTest(const int &value)
{
	m_list->DeleteAll(value);
}

Node* CTestDlist::LookupTest(const int &value)
{
	return m_list->Lookup(value);
}

Node* CTestDlist::HeadTest()
{
	return m_list->Head();
}

Node* CTestDlist::TailTest()
{
	return m_list->Tail();
}

void CTestDlist::ReserveTest()
{
	m_list->Reserve();
}

void CTestDlist::PrintTest()
{
	m_list->Print();
}

void CTestDlist::ClearTest()
{
	m_list->Clear();
}

//////////////////////////////////////

#include "Configure.h"

#ifdef TEST_DLIST

int main()
{
	CTestDlist test;

	int array1[] = { 54, 38, 96, 23, 15, 72, 150, 6, 60, 45, 83 };
	int size1 = sizeof(array1) / sizeof(int);
	for (int i = 0; i < size1; i++) {
		test.InsertTest(array1[i]);
		Node* head = test.HeadTest();
		Node* tail = test.TailTest();
		printf("h:%d, t:%d\n", head->value, tail->value);
	}
	test.PrintTest();

	test.ReserveTest();
	test.PrintTest();
	Node* head = test.HeadTest();
	Node* tail = test.TailTest();
	printf("h:%d, t:%d\n", head->value, tail->value);

	test.ReserveTest();
	test.PrintTest();
	head = test.HeadTest();
	tail = test.TailTest();
	printf("h:%d, t:%d\n", head->value, tail->value);

	test.DeleteTest(45);
	test.PrintTest();
	head = test.HeadTest();
	tail = test.TailTest();
	printf("h:%d, t:%d\n", head->value, tail->value);

	test.DeleteTest(6);
	test.PrintTest();
	head = test.HeadTest();
	tail = test.TailTest();
	printf("h:%d, t:%d\n", head->value, tail->value);

	test.DeleteTest(150);
	test.PrintTest();
	head = test.HeadTest();
	tail = test.TailTest();
	printf("h:%d, t:%d\n", head->value, tail->value);

	Node* node = test.LookupTest(72);
	printf("node->value:%d\n", node->value);
	
	test.ClearTest();
	test.PrintTest();
#if 0
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
#endif
	return 0;
}

#endif