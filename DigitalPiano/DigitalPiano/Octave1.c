#include <stdio.h>
#include <math.h>

void print_frequency(int octave);

void main() {
	char *scale[] = { "��", "��#", "��", "��#", "��", "��", "��#", "��", "��#", "��", "��#", "��" };
	int i, octave, count = 0;

	printf("< ����� ���ļ� >\n\n����\t");
	for (i = 0; i < 12; i++)
		printf("%-5s", scale[i]);
	puts("");

	for (i = 0; i <= 70; i++)
		printf("-");
	puts("");

	for (octave = 1; octave < 7; octave++)
		print_frequency(octave);
}

void print_frequency(int octave) {
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.), temp;

	temp = do_scale * pow(2., octave - 1);
	printf("%d��Ÿ�� : ", octave);
	for (int i = 0; i < 12; i++) {
		printf("%4ld ", (unsigned long)(temp + 0.5));
		temp *= ratio;
	}

	printf("\n");
}