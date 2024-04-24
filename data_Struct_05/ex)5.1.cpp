/*
프로그램 내용: 연결리스트로 스택 구현
실습날짜: 2024 - 04 - 24
학번: 202111001
이름: 이동재
*/

// 5.7, 5.8 
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkNode {
	Element data;
	struct LinkNode* link;
} Node;

Node* top = NULL;

void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};

int is_empty() { return top == NULL; }
void init_stack() { top = NULL; }
//int size()

void push(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;

	p->link = top;
	top = p;
}

int main()
{

}