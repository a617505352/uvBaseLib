#include "slist.h"
#include <stdlib.h>
#include <string.h>

CSlist::CSlist()
{
	m_head = (Node*)malloc(sizeof(Node));
	m_head->next	= NULL;
	m_head->value	= 0;
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

void CSlist::Print()
{
	if (m_head == NULL) {
		return;
	}

	Node* cur = m_head->next;

	for (; cur != NULL;) {
		printf(" %d ", cur->value);
	}
	printf("\n");

	return;
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