#ifndef _UV_LIB_DLIST_H_
#define _UV_LIB_DLIST_H_

#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node* next;
	struct Node* prev;
} Node;

typedef enum Rule
{
	sort_rule_unknow = 0,
	sort_rule_desc,
	sort_rule_asc,
	sort_rule_max,
} Rule;

class CDlist
{
public:
	CDlist();
	~CDlist();

public:
	int Insert(const int &value);
	int DeleteFirst(const int &value);
	int DeleteAll(const int &value);
	int Clear(void);
	int GetRule(Rule &rule);
	int Reserve(void);

	Node* Lookup(const int &value);
	Node* Head(void);
	Node* Tail(void);

	void Print(void);

private:
	Node*	alloc_node(const int &value);
	void	free_node(Node* node);
	int		asc_insert(const int &value);
	int		desc_insert(const int &value);

private:
	Rule	m_rule;
	Node*	m_head;
	Node*	m_tail;
};

#endif
