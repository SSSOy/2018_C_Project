#include "OodEven.h"

void main() {
	int ran = choiceOfCom();

	printf("---------- Ȧ�� ¦�� ���� ���� ----------\n\n");
	printf(">>>>> �� �� <<<<<\n");
	int n = choiceOfMe();

	printf("\n>>>>> �� �� <<<<<\n");
	if (whoIsWinner(ran, n))
		printf("     You WIN!!!!     \n\n");
	else
		printf("     Computer WIN     \n\n");

	printf("*��ǻ���� ������ %d\n", ran);
	printf("*����� ������ ");

	if (n == 1)
		printf("Ȧ��.\n");
	else
		printf("¦��.\n");
}