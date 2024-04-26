/*
프로그램 내용: 배열을 이용한 리스트 전체 프로그램
실습날짜: 2024 - 04 - 26
학번: 202111001
이름: 이동재
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int Element;
Element data[MAX_LIST_SIZE];
int length = 0;

void error(const char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};

void init_list() { length = 0; }
void clear_list() { length = 0; }
int is_empty() { return length == 0; }
int is_full() { return length == MAX_LIST_SIZE; }
int get_entry(int id) { return data[id]; }
void replace(int id, Element e) { data[id] = e; }
int size() { return length; }

void insert(int pos, int e)  // 삽입 연산 (매개변수: 삽입할 위치, 삽입할 값)
{
	int i;
	if (is_full() == 0 && pos >= 0 && pos <= length) // 포화상태가 아닐때 and 배열의 처음이 아닐때 and 배열의 끝이 아닐때
	{
		for (i = length; i > pos; i--) // 삽입할 위치 바로 뒤에 있는 데이터들을 모두 한칸씩 뒤로 미루기
			data[i] = data[i - 1];
		data[pos] = e; // 삽입할 위치에 데이터 삽입
		length++; // 길이도 늘려주기
	}

	else error("포화상태 오류 또는 삽입 위치 오류");
}
void delete_(int pos) 
{
	int i;
	if (is_empty() == 0 && pos >= 0 && pos < length) // 공백상태가 아닐때 and 배열의 처음이 아닐때 and 배열의 끝이 아닐때
	{
		for (i = pos+1; i < length; i++) // 삭제한 위치로 데이트들을 한칸씩 당겨주기
			data[i-1] = data[i];
		
		length--; // 길이도 줄여주기
	}

	else error("공백상태 오류 또는 삭제 위치 오류");
}
int find(Element e) 
{
	int i;
	for (i = 0; i < length; i++)
		if (data[i] == e)
			return i;
	return -1;
}

void print_list(const char* msg)
{
	int i;
	printf("%s[%2d]: ", msg, length);
	for (i = 0; i < length; i++)
		printf(" %2d ", data[i]);
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
	print_list("배열로 구현한 List(삽입x5)");

	replace(2, 90);
	print_list("배열로 구현한 List(교체x1)");

	delete_(2);
	delete_(size() - 1);
	delete_(0);
	print_list("배열로 구현한 List(삭제x3)");

	clear_list();
	print_list("배열로 구현한 List(정리후)");

}

/*
* 추가할 메뉴
* f - 검색
* c - 바꾸기
* 
* 수정할 메뉴
* q - 종료
* 
* 검색 메뉴 예시
* 검색 문자열 입력: computer
* 
* 0 computer
* 4 department of computer
* 
* 바꾸기 메뉴 예시
* 검색 문자열 입력 computer
* 바꿀 문자열 입력 electrical engineering
* 
* (리스트에 수정된 내용이 있을 경우)
* 수정한 내용이 있습니다. 파일에 저장하시겟습니까?
*/  // 프로그램은 실습과제로 추가한거는 과제로 제출