#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define X_M 79
#define Y_M 24

void move_arrow_key(char chr, int *x, int *y, int x_m, int y_m);
void gotoxy(int x, int y);

void main() {
	char key;
	int x = 20, y = 3;
	do {
		gotoxy(x, y);
		printf("B");
		key = _getch();
		move_arrow_key(key, &x, &y, X_M, Y_M);
	} while (key != 27);
}

void move_arrow_key(char key, int *x, int *y, int x_m, int y_m) {
	switch (key) {
	case 72 : //위 화살표
		if(*y >= 0)
			(*y)--;
		break;
	case 80 : //아래 화살표
		if (*y <= y_m)
			(*y)++;
		break;
	case 75 : //왼쪽 화살표
		if (*x >= 0)
			(*x)--;
		break;
	case 77 : //오른쪽 화살표
		if (*x <= x_m)
			(*x)++;
		break;
	}
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
