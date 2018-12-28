#ifndef _UV_LIB_SLIST_H_
#define _UV_LIB_SLIST_H_

#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

typedef enum Rule
{
	rule_unknow = 0,
	rule_desc = 1,
	rule_asc,
	rule_max,
} Rule;

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
	int Clear(void);
	Node* LookUp(const int &value);
	Node* Head();
	void Print();
	Rule GetSortRule();

private:
	Node* alloc_node(const int &value);
	void free_node(Node* node);
	int asc_insert(const int &value);
	int desc_insert(const int &value);

private:
	Node* m_head;
	Rule  m_rule;
};

#endif
