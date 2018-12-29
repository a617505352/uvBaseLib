#include "dlist.h"
#include <stdlib.h>
#include <string.h>

CDlist::CDlist()
{
	m_rule = sort_rule_asc;
	m_head = NULL;
	m_tail = NULL;
}

CDlist::~CDlist()
{
	if (m_head == NULL) {
		return;
	}

	for (; m_head != NULL;) {
		Node* tmp = m_head;
		m_head = m_head->next;
		free_node(tmp);
	}
}

int CDlist::Insert(const int &value)
{
	if (m_rule == sort_rule_asc) {
		return asc_insert(value);
	} else {
		return desc_insert(value);
	}
}

int CDlist::DeleteFirst(const int &value)
{
	if (m_head == NULL) {
		printf("empty double-link list.\n");
		return -1;
	}

	Node* cur = m_head;
	for (; cur != NULL;) {
		if (cur->value == value) {
			if (cur == m_head) {
				cur->next->prev = NULL;
				m_head = cur->next;
			} else if (cur == m_tail) {
				cur->prev->next = NULL;
				m_tail = cur->prev;
			} else {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
			}
			free_node(cur);

			return 0;
		}

		cur = cur->next;
	}

	printf("can't find value in double-link list.\n");
	return -2;
}

int CDlist::DeleteAll(const int &value)
{
	if (m_head == NULL) {
		printf("empty double-link list.\n");
		return -1;
	}

	Node* tmp = NULL;
	Node* cur = m_head;
	for (; cur != NULL;) {
		if (cur->value == value) {
			tmp = cur;
			cur = cur->next;
			if (tmp == m_head) {
				m_head = cur;
				cur->prev = NULL;
			} else if (tmp == m_tail) {
				m_tail = tmp->prev;
				tmp->prev->next = NULL;
			} else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}

			free_node(tmp);
		} else {
			cur = cur->next;
		}
	}

	printf("can't find value in double-link list.\n");

	return -2;
}

int CDlist::Clear(void)
{
	if (m_head == NULL) {
		return -1;
	}

	for (; m_head != NULL;) {
		Node* tmp = m_head;
		m_head = m_head->next;
		free_node(tmp);
	}

	m_head = NULL;
	m_tail = NULL;

	return 0;
}

int CDlist::GetRule(Rule &rule)
{
	rule = m_rule;

	return 0;
}

int CDlist::Reserve(void)
{
	if (m_head == m_tail) {
		return 0;
	}

	Node *cur	= m_head;
	Node *head	= m_head;

	while (1) {
		if (cur == NULL) {
			break;
		}

		Node* tmp = cur->next;

		cur->next = head;
		cur->prev = NULL;
		head->prev = cur;

		head = cur;
		cur = tmp;
	}

	m_tail = m_head;
	m_tail->next = NULL;

	m_head = head;
	m_head->prev = NULL;

	return 0;
}

Node* CDlist::Lookup(const int &value)
{
	Node* cur = m_head;
	for (; cur != NULL;) {
		if (cur->value == value) {
			return cur;
		} 

		cur = cur->next;
	}

	return NULL;
}

Node* CDlist::Head(void)
{
	return m_head;
}

Node* CDlist::Tail(void)
{
	return m_tail;
}

void CDlist::Print(void)
{
	Node* cur = m_head;
	for (; cur != NULL;) {
		printf(" %d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

Node* CDlist::alloc_node(const int &value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->prev	= NULL;
	node->next	= NULL;

	return node;
}

void CDlist::free_node(Node* node)
{
	if (node != NULL) {
		free(node);
		node = NULL;
	}
}

int CDlist::asc_insert(const int &value)
{
	Node* node = alloc_node(value);

	if (m_head == NULL) {
		m_head = node;
		m_tail = node;
	} else {
		Node* cur = m_head;
		for (; cur != NULL;) {
			if (cur->value > value) {
				if (cur == m_head) {
					node->next = cur;
					cur->prev = node;
					m_head = node;
				} else {
					cur->prev->next = node;
					node->prev = cur->prev;
					node->next = cur;
					cur->prev = node;
				}
				break;
			}

			cur = cur->next;
		}

		if (cur == NULL) {
			m_tail->next = node;
			node->prev = m_tail;
			m_tail = node;
		}
	}

	return 0;
}

int CDlist::desc_insert(const int &value)
{
	Node* node = alloc_node(value);

	if (m_head == NULL) {
		m_head = node;
		m_tail = node;
	} else {
		Node* cur = m_head;
		for (; cur != NULL;) {
			if (cur->value < value) {
				if (cur == m_head) {
					node->next = cur;
					cur->prev = node;
					m_head = node;
				} else {
					cur->prev->next = node;
					node->prev = cur->prev;
					node->next = cur;
					cur->prev = node;
				}
				break;
			}

			cur = cur->next;
		}

		if (cur == NULL) {
			m_tail->next = node;
			node->prev = m_tail;
			m_tail = node;
		}
	}

	return 0;
}
