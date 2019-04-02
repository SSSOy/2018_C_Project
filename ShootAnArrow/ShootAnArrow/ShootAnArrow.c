#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void gotoxy(int x, int y);
void intro_game();
void draw_rectangle(int r, int c);
void display_text(int count, int win);
void game_control(int *r_c, int rnd, int *speed, int cnt);
void horizontal_slide(int x, int y, char *c2, int *speed);
int level = 1;

void main() {
	int count = 0, rnd, speed = 100;
	int r_count = 0;
	char *target = "▼"; 
	srand((unsigned int)time(NULL));
	intro_game();
	
	while (1) {
		system("cls");
		draw_rectangle(35, 20);
		rnd = rand() % 30 + 4;
		gotoxy(rnd, 2);
		printf("%s", target);
		count++;
		display_text(count, r_count);
		game_control(&r_count, rnd, &speed, count);
	}
}

void intro_game() {
	printf("< 말타며 활쏘기 게임~~!!!! >\n");
	printf("말을 타고 이동하면서 \n");
	printf("목표물!!을 맞추는 게임!!\n");
	printf("화살 발사 : 스페이스 키\n\n");
	printf("게임을 시작하려면 아무키나 누르세요'ㅅ'!! GO~~~!!\n");
	_getch();
}

void display_text(int count, int win) {
	gotoxy(45, 3);
	printf("화살 발사는 스페이스 키!");
	gotoxy(45, 5);
	printf("총 게임 제한 횟수 : 10회");
	gotoxy(45, 7);
	printf("▷ 횟수 : %d", count);
	gotoxy(45, 9);
	printf("▶ 성공 : %d", win);
	gotoxy(45, 11);
	printf("▷ 레벨 : %d", level);
	gotoxy(45, 18);
	printf("종료하려면 ESC를 누르세요\n");
}

void game_control(int *r_c, int rnd, int *speed, int cnt) {
	char c;
	char *ch = "♣";
	char *cc = "↑";
	int i = 2, k = 1, e = 0;
	
	do {
		i += k;
		if (i > 33)
			k = -1;
		else if (i < 3)
			k = 1;
		horizontal_slide(i + 1, 21, ch, speed);
	} while (!_kbhit());

	c = _getch();
	if (c == 27) {
		Sleep(700);
		system("cls");
		gotoxy(10, 10);
		printf("당신은 전생에 장군이었군요!!^^\n");
		gotoxy(10, 11);
		printf("총 %d번 중 %d번을 맞혔습니다~~!\n", *r_c);
		gotoxy(10, 12);
		printf("       정말 대단해요!!\n\n\n\n\n");

		exit(0);
	}
	else if (c == 32) {
		for (int j = 20; j > 2; j--) 
			horizontal_slide(i, j, cc, speed);
		gotoxy(i, 2);
		if (rnd - 1 <= i && i <= rnd + 1) {
			printf("☆"); 
			(*r_c)++;
			e = 1;
			gotoxy(45, 13);
			printf("명중!!!!!!!!!!");
			Sleep(700);
		}
	}
	if (*r_c != 0) {
		if (*r_c % 3 == 0 && e != 0) {
			system("cls");
			gotoxy(10, 8);
			level++;
			printf("레벨 업!!");
			Beep(262, 300);
			Beep(311, 300);
			Beep(370, 300);
			Beep(494, 300);
			Sleep(1000);
			*speed -= 10;
		}
	}
}

void horizontal_slide(int x, int y, char *c2, int *speed) {
	gotoxy(x, y);
	printf("%s", c2);
	Sleep(*speed);
	printf("\b\b  ");
}

void draw_rectangle(int c, int r) {
	unsigned char a = 0xA6, b[8];
	for (char i = 1; i < 8; i++)
		b[i] = 0xA0 + i;

	printf("%c%c", a, b[3]);
	for (int i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c\n", a, b[4]);
	for (int i = 0; i < r; i++) {
		printf("%c%c", a, b[2]);
		for (int i = 0; i < c; i++)
			printf(" ");
		printf("%c%c\n", a, b[2]);
	}
	printf("%c%c", a, b[6]);
	for (int i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c\n", a, b[5]);
	
}

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}