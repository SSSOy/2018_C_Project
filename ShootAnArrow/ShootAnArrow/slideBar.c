#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void gotoxy(float x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_rect(int c, int r);
void draw_verical_slide(int x, int y, int length, char *s);
void draw_horizental_slide(int x, int y, int length, char *s);
void move_arrow_key(int *x, int *y, char key, int x_m, int y_m);

int main() {
	int c, r;
	char *slide = "■", key;
	int x = 1, y = 1;
	int h_slide_length, v_slide_length;

	printf("[ 슬라이드바 표시 ]\n\n");
	printf("수평 슬라이드바의 길이(최대 70) : ");
	scanf("%d", &h_slide_length);
	printf("수직 슬라이드바의 길이(최대 70) : ");
	scanf("%d", &v_slide_length);
	system("cls");

	do {
		draw_verical_slide(1, y, v_slide_length, slide);
		draw_horizental_slide(x, v_slide_length + 3, h_slide_length + 2, slide);
		key = _getch();
		move_arrow_key(&x, &y, key, h_slide_length, v_slide_length - 1);
	} while (key != 27);
}


void draw_rect(int c, int r) {
	unsigned char a = 0xA6, b[8];
	for (char i = 1; i < 8; i++)
		b[i] = 0xA0 + i;

	printf("%c%c", a, b[3]);
	for (int i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c\n", a, b[4]);
	for (int i = 0; i < r; i++) {
		printf("%c%c", a, b[2]);
		for(int i = 0; i < c; i++)
			printf(" ");
		printf("%c%c\n", a, b[2]);
	}
	printf("%c%c", a, b[6]);
	for(int i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c\n", a, b[5]);
}

void draw_verical_slide(int x, int y, int length, char *s) {
	gotoxy(1, 1);
	draw_rect(2, length, s);
	gotoxy(x + 1, y + 1);
	printf("%s", s);
	gotoxy(x + 5, length + 1);
	printf("%-2d", y);
}

void draw_horizental_slide(int x, int y, int length, char *s) {
	gotoxy(1, y);
	draw_rect(length, 1);
	gotoxy(x + 2, y + 1);
	printf("%s", s);
	gotoxy(length + 2, y + 3);
	printf("%-2d", x);
}

void move_arrow_key(int *x, int *y, char key, int x_m, int y_m) {
	switch (key) {
	case 72: //위 화살표
		if (*y > 1 )
			(*y)--;
		break;
	case 80: //아래 화살표
		if (*y <= y_m)
			(*y)++;
		break;
	case 75: //왼쪽 화살표
		if (*x > 1)
			(*x)--;
		break;
	case 77: //오른쪽 화살표
		if (*x < x_m)
			(*x)++;
		break;
	}
}