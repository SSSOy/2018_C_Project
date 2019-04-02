#include <stdio.h>
#include <Windows.h>

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	gotoxy(20, 1);
	printf("< 5단 구구단 >");
	for (int i = 1; i < 10; i++) {
		gotoxy(20, i + 1);
		printf("5 * %d = %d", i, 5 * i);
	}
}