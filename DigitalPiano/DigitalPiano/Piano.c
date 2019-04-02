#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_square(int size, int size2) {
	unsigned char a = 0xA6, b[12];
	for (char i = 1; i < 12; i++)
		b[i] = 0xA0 + i;

	printf("%c%c ", a, b[3]);
	for (int i = 0; i < size - 1; i++) {
		printf("%c%c ", a, b[1]);
		printf("%c%c ", a, b[8]);
	}
	printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[4]);
	puts("");


	for (int i = 0; i < size2 - 1; i++) {

		printf("%c%c", a, b[2]);
		for (int j = 0; j < size - 1; j++) {
			printf("   ");
			printf("%c%c", a, b[2]);
		}
		printf("  ");
		printf(" %c%c\n", a, b[2]);

		printf("%c%c ", a, b[7]);
		for (int j = 0; j < size - 1; j++) {
			printf("%c%c ", a, b[1]);
			printf("%c%c ", a, b[11]);
		}
		printf("%c%c ", a, b[1]);
		printf("%c%c\n", a, b[9]);
	}

	printf("%c%c", a, b[2]);
	for (int j = 0; j < size - 1; j++) {
		printf("   ");
		printf("%c%c", a, b[2]);
	}
	printf("  ");
	printf(" %c%c\n", a, b[2]);

	printf("%c%c ", a, b[6]);
	for (int i = 0; i < size - 1; i++) {
		printf("%c%c ", a, b[1]);
		printf("%c%c ", a, b[10]);
	}
	printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[5]);
	puts("");
}

void main() {
	int c = 1;
	char piano[8][3] = { "도", "레", "미", "파", "솔", "라", "시", "도" };

	printf("<  Digital Piano >\n\n");
	printf("키보드의 숫자를 누르면 해당 건반에 음이 표시되고, \n");
	printf("해당 음이 스피커로 출력됩니당'ㅅ' (프로그램 종료 : ESC)\n");

	draw_square(8, 2);

	for (int i = 3; i < 4 * 8 + 3; i += 4) {
		gotoxy(i, 6);
		printf("%d", c);
		c++;
	}
	c = 0;
	for (int i = 3; i < 4 * 8 + 3; i += 4) {
		gotoxy(i, 8);
		printf("%s", piano[c]);
		c++;
	}
	gotoxy(1, 2 * 3 + 4);
}