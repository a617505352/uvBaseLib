#include "slist.h"
#include <stdlib.h>
#include <string.h>

CSlist::CSlist()
{
	m_head = (Node*)malloc(sizeof(Node));
	m_head->next	= NULL;
	m_head->value	= 0;

	m_rule = rule_asc;
}

CSlist::~CSlist()
{
	for (; m_head != NULL && m_head->next != NULL;) {
		Node* tmp = m_head->next;
		m_head->next = m_head->next->next;
		free_node(tmp);
	}
	free_node(m_head);
}

int CSlist::Insert(const int &value)
{
	if (m_rule == rule_asc) {
		return asc_insert(value);
	} else {
		return desc_insert(value);
	}
}

int CSlist::DeleteFir(const int &value)
{
	if (m_head == NULL) {
		return -1;
	}

	Node* prev = m_head;
	Node* cur = prev->next;

	for (; cur != NULL;) {
		if (cur->value == value) {
			prev->next = cur->next;
			free_node(cur);
			return 0;
		} else {
			prev = cur;
			cur = prev->next;
		}
	}

	return -2;
}

int CSlist::DeleteAll(const int &value)
{
	if (m_head == NULL) {
		return -1;
	}

	Node* prev			= m_head;
	Node* cur			= prev->next;
	bool value_exist	= false;

	for (; cur != NULL;) {
		if (cur->value == value) {
			prev->next = cur->next;
			free_node(cur);
			cur = prev->next;
			value_exist = true;
		} else {
			prev = cur;
			cur = prev->next;
		}
	}

	if (value_exist) {
		return 0;
	} else {
		return -2;
	}
}

int CSlist::Reserve(void)
{
	if (m_head == NULL) {
		return -1;
	}

	if (m_rule == rule_asc) {
		m_rule = rule_desc;
	} else {
		m_rule = rule_asc;
	}

	Node* cur  = m_head->next;
	Node* head = cur;

	while(1) {
		if (cur == NULL || cur->next == NULL) {
			break;
		}

		Node* tmp		= cur->next;
		cur->next		= cur->next->next;
		m_head->next	= tmp;
		tmp->next		= head;
		head			= tmp;
	}

	return 0;
}

int CSlist::Clear(void)
{
	for (; m_head != NULL && m_head->next != NULL;) {
		Node* tmp = m_head->next;
		m_head->next = m_head->next->next;
		free_node(tmp);
	}

	return 0;
}

Node* CSlist::LookUp(const int &value)
{
	if (m_head == NULL) {
		return NULL;
	}

	Node* cur = m_head->next;

	for (; cur != NULL;) {
		if (cur->value == value) {
			return cur;
		} else {
			cur = cur->next;
		}
	}

	return NULL;
}

Node* CSlist::Head()
{
	if (m_head == NULL) {
		return NULL;
	}

	return m_head->next;
}

void CSlist::Print()
{
	if (m_head == NULL) {
		return;
	}

	Node* cur = m_head->next;

	for (; cur != NULL;) {
		printf(" %d ", cur->value);
		cur = cur->next;
	}
	printf("\n");

	return;
}

Rule CSlist::GetSortRule()
{
	return m_rule;
}

Node* CSlist::alloc_node(const int &value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));

	node->next  = NULL;
	node->value = value;

	return node;
}

void CSlist::free_node(Node* node)
{
	if (node != NULL) {
		free(node);
		node = NULL;
	}
}

int CSlist::asc_insert(const int &value)
{
	if (m_head == NULL) {
		return -1;
	}

	Node* prev = m_head;
	Node* cur = prev->next;

	for (; cur != NULL;) {
		if (cur->value > value) {
			Node* node = alloc_node(value);
			prev->next = node;
			node->next = cur;
			break;
		}

		prev = cur;
		cur = prev->next;
	}

	if (cur == NULL) {
		Node* node = alloc_node(value);
		prev->next = node;
	}

	return 0;
}

int CSlist::desc_insert(const int &value)
{
	if (m_head == NULL) {
		return -1;
	}

	Node* prev = m_head;
	Node* cur = prev->next;

	for (; cur != NULL;) {
		if (cur->value < value) {
			Node* node = alloc_node(value);
			prev->next = node;
			node->next = cur;
			break;
		}

		prev = cur;
		cur = prev->next;
	}

	if (cur == NULL) {
		Node* node = alloc_node(value);
		prev->next = node;
	}

	return 0;
}
