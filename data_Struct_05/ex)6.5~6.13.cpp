/*
���α׷� ����: �ܼ����Ḯ��Ʈ�� �̿��� ����Ʈ ��ü ���α׷�
�ǽ���¥: 2024 - 04 - 26
�й�: 202111001
�̸�: �̵���
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link; // ��ü ���� ����ü
} Node;

Node* head = NULL; // 

void init_list() { head = NULL; }
int is_empty() { return head == NULL; }

Node* get_entry(int pos) 
{
	Node* p = head;
	int i;
	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL)
			return NULL;
	return p;
}

int size() 
{
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
		count++;
	return count++;
}

Node* find(Element val)
{

}
void replace(int pos, Element val) 
{

}

void insert_next(Node *prev, Node *n){}
void insert(int pos, Element val) {}
Node* remove_next(Node *prev){}
void delete_(int pos){}
void clear_list(){}
void print_list(const char* msg)
{
	Node* p;
	printf("%s[%2d]: ", msg, size());
	for (p = head; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");

}

void main()
{
	init_list();
	insert(0, 10);
	insert(0, 20);
	insert(1, 30);
	insert(size(), 40);
	insert(2, 50);
	print_list("�ܼ����Ḯ��Ʈ�� ������ List(����x5)");

	replace(2, 90);
	print_list("�ܼ����Ḯ��Ʈ�� ������ List(��üx1)");

	delete_(2);
	delete_(size() - 1);
	delete_(0);
	print_list("�ܼ����Ḯ��Ʈ�� ������ List(����x3)");

	clear_list();
	print_list("�ܼ����Ḯ��Ʈ�� ������ List(������)");
}