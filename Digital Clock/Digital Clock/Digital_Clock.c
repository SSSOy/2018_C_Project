#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>


int zero[20] = { 1, 1, 1, 1,
1, 0, 0, 1,
1, 0, 0, 1,
1, 0, 0, 1,
1, 1, 1, 1 };
int one[20] = { 0, 0, 0, 1,
0, 0, 0, 1,
0, 0, 0, 1,
0, 0, 0, 1 ,
0, 0, 0, 1 };
int two[20] = { 1, 1, 1, 1,
0, 0, 0, 1,
1, 1, 1, 1,
1, 0, 0, 0,
1, 1, 1, 1 };
int three[20] = { 1, 1, 1, 1,
0, 0, 0, 1,
1, 1, 1, 1,
0, 0, 0, 1,
1, 1, 1, 1 };
int four[20] = { 1, 0, 0, 1,
1, 0, 0, 1,
1, 1, 1, 1,
0, 0, 0, 1,
0, 0, 0, 1 };
int five[20] = { 1, 1, 1, 1,
1, 0, 0, 0,
1, 1, 1, 1,
0, 0, 0, 1,
1, 1, 1, 1 };
int six[20] = { 1, 1, 1, 1,
1, 0, 0, 0,
1, 1, 1, 1,
1, 0, 0, 1,
1, 1, 1, 1 };
int seven[20] = { 1, 1, 1, 1,
1, 0, 0, 1,
1, 0, 0, 1,
0, 0, 0, 1,
0, 0, 0, 1 };
int eight[20] = { 1, 1, 1, 1,
1, 0, 0, 1,
1, 1, 1, 1,
1, 0, 0, 1,
1, 1, 1, 1 };
int nine[20] = { 1, 1, 1, 1,
1, 0, 0, 1,
1, 1, 1, 1,
0, 0, 0, 1,
0, 0, 0, 1 };

void digit_print(int *num, int line) {
	for (int i = line * 4; i < line * 4 + 4; i++) {
		if (num[i] == 1)
			printf("■");
		else
			printf("  ");
	}
	printf("    ");
}
void number_chek(int k, int line) {
	if (k >= 1) {

		number_chek(k / 10, line);
		switch (k % 10) {
		case 0:		digit_print(zero, line);		break;
		case 1:		digit_print(one, line);			break;
		case 2:		digit_print(two, line);			break;
		case 3:		digit_print(three, line);		break;
		case 4:		digit_print(four, line);		break;
		case 5:		digit_print(five, line);			break;
		case 6:		digit_print(six, line);			break;
		case 7:		digit_print(seven, line);		break;
		case 8:		digit_print(eight, line);		break;
		case 9:		digit_print(nine, line);		break;
		}
	}
}
long time_to_number() {
	long ptime;
	time_t now;
	struct tm *d;
	time(&now);

	now = time(NULL);
	d = localtime(&now);

	ptime = (d->tm_hour * 10000) + (d->tm_min * 100) + (d->tm_sec);

	return ptime;
}

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void dot_print(int h) {
	if (h < 100000) {	//0:00:00
		for (int i = 1; i < 5; i++) {
			if (i % 2 != 0) {
				gotoxy(12 * i, 4);
				printf("■");
				gotoxy(12 * i, 6);
				printf("■");
			}
		}
	}
	else {						//00:00:00
		for (int i = 1; i < 5; i++) {
			if (i % 2 == 0) {
				gotoxy(12 * i, 4);
				printf("■");
				gotoxy(12 * i, 6);
				printf("■");
			}
		}
	}
}

int main() {
	long time_number;

	printf("\n   < 디지털 숫자 출력 >   \n");
	printf("아무 키나 누르면 현재 시간을 보여줍니다.\n\n");
	_getch();

	while (!_kbhit()) {
		Sleep(1000);
		system("cls");
		time_number = time_to_number();

		for (int line = 0; line < 5; line++) {
			gotoxy(3, 3 + line);
			number_chek(time_number, line);
			printf("\n");
		}
		dot_print(time_number);

		puts("\n\n");
		gotoxy(15, 10);
		printf("아무 키나 누르면 종료합니다.\n");
	}
}