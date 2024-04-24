/*
���α׷� ����: ���Ḯ��Ʈ�� ���� ����
�ǽ���¥: 2024 - 04 - 24
�й�: 202111001
�̸�: �̵���
*/

// 5.7, 5.8 
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkNode {
	Element data;
	struct LinkNode* link; // ��ü ���� ����ü
} Node;

Node* top = NULL; // ������ ��� (NULL ������ �ʱ�ȭ)

void error(const char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};

int is_empty() { return top == NULL; }
void init_stack() { top = NULL; }

int size() 
{
	Node* p;
	int count = 0;
	for (p = top; p != NULL; p = p->link)
		count++;
	return count++;
}

void push(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;

	p->link = top;
	top = p;
}

Element pop() 
{
	Node* p;
	Element e;
	if (is_empty())
		error("���� ���� ����");

	p = top;
	top = p->link;
	e = p->data;
	free(p);
	return e;
}
Element peek()
{
	if(is_empty())
		error("���� ���� ����");
	return top->data;
}
void destroy_stack() 
{
	while (is_empty() == 0)
		pop();
}

void print_stack(const char* msg)
{
	Node* p;
	printf("%s[%2d]= ", msg, size());
	for (p = top; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}



int main()
{
	int i;

	init_stack();
	for (i = 1; i < 10; i++)
		push(i);
	print_stack("����Ƚ��� push 9ȸ");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("����Ƚ��� push 3ȸ");
	destroy_stack();
	print_stack("����Ƚ��� destroy");
}