#include <stdio.h>
#include <math.h>
#include <Windows.h>

int calc_frequency(int octave, int idx);

void main() {
	int index[] = { 0, 2, 4, 5, 7, 9, 11, 12 };
	int freq[8];

	for (int i = 0; i < 8; i++) 
		freq[i] = calc_frequency(4, index[i]);
	
	for (int i = 0; i < 8; i++) {
		Beep(freq[i], 300);
		Sleep(500);
	}
	Sleep(500);
	puts("");
	for (int i = 7; i >= 0; i--) {
		Beep(freq[i], 300);
		Sleep(500);
	}
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