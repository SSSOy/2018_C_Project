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
	for (int i = 0; i < size - 1 ; i++) {
		printf("%c%c ", a, b[1]);
		printf("%c%c ", a, b[10]);
	}
	printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[5]);
	puts("");
}

void main() {
	int x, y;
	printf("< �ٵ��� �׸��� >\n\n");
	printf("���� ���� (�ִ� 37) �Է� : ");
	scanf("%d", &x);
	printf("���� ���� (�ִ� 37) �Է� : ");
	scanf("%d", &y);
	draw_square(x, y);

	gotoxy(3, 6); printf("��");
	gotoxy(7, 6); printf("��");
	gotoxy(11, 6); printf("��");
	gotoxy(3, 8); printf("��");
	gotoxy(7, 8); printf("��");
	gotoxy(11, 8); printf("��");
	gotoxy(1, y * 3 + 4);
}