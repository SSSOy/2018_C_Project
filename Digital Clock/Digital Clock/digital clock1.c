#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


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
						1, 1, 1, 1};
int three[20] = { 1, 1, 1, 1,
					 	0, 0, 0, 1,
						1, 1, 1, 1,
						0, 0, 0, 1,
						1, 1, 1, 1 };
int four[20] = { 1, 0, 0, 1,
						1, 0, 0, 1,
						1, 1, 0, 1,
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
	printf("  ");
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

int main() {
	int num;
	char ch;

	do {
		system("cls");
		printf("\n   < 디지털 숫자 출력 >   \n");
		printf(" 1 이상의 정수를 입력하세요.\n\n");
		printf("숫자 입력 : ");
		scanf("%d", &num);
		puts("\n");

		for (int line = 0; line < 5; line++) {
			number_chek(num, line);
			printf("\n");
		}

		puts("\n\n");
		printf("종료 : ESC ");
		ch = _getch();

	} while (ch != 27);
}