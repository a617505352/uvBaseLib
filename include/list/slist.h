#ifndef _UV_LIB_SLIST_H_
#define _UV_LIB_SLIST_H_

#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

class CSlist
{
public:
	CSlist();
	~CSlist();

public:
	int Insert(const int &value);
	int DeleteFir(const int &value);
	int DeleteAll(const int &value);
	int Reserve(void);
	Node* LookUp(const int &value);
	void Print();

private:
	Node* alloc_node(const int &value);
	void free_node(Node* node);

private:
	Node* m_head;
};

#endif
