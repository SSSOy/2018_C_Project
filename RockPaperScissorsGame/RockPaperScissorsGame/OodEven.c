#include "OodEven.h"

int choiceOfCom() {
	srand((unsigned)time(NULL));
	int ran = rand() % 100;
	return ran;
}
int choiceOfMe() {
	int n;
	printf("홀수이면 1, 짝수이면 2를 입력 : ");
	scanf("%d", &n);
	return n;
}
int whoIsWinner(int com, int n) {
	int result;

	if (com % 2 == 0)
		result = 2;
	else
		result = 1;
	if (result == n)
		return 1;
	else
		return 0;
}