#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void main() {
	char *text = "color 1E";
	system(text);
	printf("아무키나 누르면\n");
	printf("이전 색으로 돌아갑니다.\n");
	_getch();
	system("color 8D");
}