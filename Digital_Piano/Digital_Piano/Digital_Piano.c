#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>

void arrow_key(char key, int *x, int *y, int x_m, int y_m);
void gotoxy(int x, int y);
int calc_frequency(int octave, int idx);
void piano();
void draw_square(int size, int size2);

void main() {
	int c = 1;
	char p[8][3] = { "��", "��", "��", "��", "��", "��", "��", "��" };

	printf("<  Digital Piano >\n\n");
	printf("Ű������ ���ڸ� ������ �ش� �ǹݿ� ���� ǥ�õǰ�, \n");
	printf("�ش� ���� ����Ŀ�� ��µ˴ϴ�! (���α׷� ���� : ESC)\n\n");
	printf("-����Ű-\n");
	printf("�� : �ѿ�Ÿ�� ����\t�� : �ѿ�Ÿ�� �Ʒ���\n");
	printf("�� : �� �����ð� ª��\t�� : �� �����ð� ���\n\n");

	draw_square(8, 2);

	for (int i = 3; i < 4 * 8 + 3; i += 4) {
		gotoxy(i, 11);
		printf("%d", c);
		c++;
	}
	c = 0;
	for (int i = 3; i < 4 * 8 + 3; i += 4) {
		gotoxy(i, 13);
		printf("%s", p[c]);
		c++;
	}
	gotoxy(1, 2 * 3 + 6);

	piano();
}

int calc_frequency(int octave, int inx) {
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.), temp;

	temp = do_scale * pow(2, octave - 1);

	for (int i = 0; i < inx; i++) {
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
}

void piano() {
	char p[8][3] = { "��", "��", "��", "��", "��", "��", "��", "��" };
	int index[] = { 0, 2, 4, 5, 7, 9, 11, 12 };
	int freq[8], code;
	int octave = 4;
	int time = 500;

	do {
		for (int i = 0; i < 8; i++)
			freq[i] = calc_frequency(octave, index[i]);
		code = _getch();
		if ('1' <= code && code <= '8') {
			code -= '1';
			gotoxy(3 + (4 * code), 13);
			printf("��");
			Sleep(300);
			gotoxy(3 + (4 * code), 13);
			printf("%s", p[code]);
			Beep(freq[code], time);
			Sleep(time);
		}
		else {
			arrow_key(code, &time, &octave, 2000, 6);
		}
		gotoxy(1, 15);
		printf("���� ��Ÿ�� : %d, ���� �����ð� %.2f��\n", octave, (float)time / 1000);
	} while (code != 27);
}

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

void arrow_key(char key, int *x, int *y, int x_m, int y_m) {
	switch (key) {
	case 72: //�� ȭ��ǥ
		if (*y <= y_m)
			(*y)++;
		break;
	case 80: //�Ʒ� ȭ��ǥ
		if (*y >= 1)
			(*y)--;
		break;
	case 75: //���� ȭ��ǥ
		if (*x >= 300)
			(*x) -= 250;
		break;
	case 77: //������ ȭ��ǥ
		if (*x <= x_m)
			(*x) += 250;
		break;
	}
}