#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void draw_square(int size, int size2) {
	unsigned char a = 0xA6, b[7];
	for (char i = 1; i < 7; i++)
		b[i] = 0xA0 + i;

	printf("%c%c", a, b[3]);
	for (int i = 0; i < size; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[4]);
	puts("");

	for (int i = 0; i < size2; i++) {
		printf("%c%c", a, b[2]);
		for (int j = 0; j < size; j++)
			printf("  ");
		printf("%c%c\n", a, b[2]);
	}

	printf("%c%c", a, b[6]);
	for (int i = 0; i < size; i++)
		printf("%c%c ", a, b[1]);
	printf("%c%c", a, b[5]);
	puts("");
}

void main() {
	int x, y;
	printf("< 직사각형 그리기 >\n\n");
	printf("가로 길이 (최대 37) 입력 : ");
	scanf("%d", &x);
	printf("세로 길이 (최대 37) 입력 : ");
	scanf("%d", &y);
	draw_square(x, y);
}