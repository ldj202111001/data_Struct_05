﻿/*
프로그램 내용: 포인터를 이용한 나이계산
실습날짜: 2024 - 04 - 12
학번: 202111001
이름: 이동재
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
    int year;
    int* py = &year; //정수형 변수 age의 주소를 포인터 pa가 가리킨다(참조한다).

    printf("출생 년도 입력: ");
    scanf_s("%d", &year);

    printf("%d\n", py);
    printf("%d\n", &year);

    *py = 2024 - *py + 1;
    printf("나이는 %d 입니다", *py);
}

// *p++  가리키는 값을 가져온 다음, 포인터를 한칸 증가 (주소증가, 배열)
// *p--  가리키는 값을 가져온 다음, 포인터를 한칸 감소 (주소감소, 배열)
// (*p)++  포인터가 가리키는 값을 증가시킨다.