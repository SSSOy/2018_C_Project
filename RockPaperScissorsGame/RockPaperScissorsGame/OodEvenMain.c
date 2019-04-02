#include "OodEven.h"

void main() {
	int ran = choiceOfCom();

	printf("---------- 홀수 짝수 게임 시작 ----------\n\n");
	printf(">>>>> 대 결 <<<<<\n");
	int n = choiceOfMe();

	printf("\n>>>>> 결 과 <<<<<\n");
	if (whoIsWinner(ran, n))
		printf("     You WIN!!!!     \n\n");
	else
		printf("     Computer WIN     \n\n");

	printf("*컴퓨터의 선택은 %d\n", ran);
	printf("*당신의 선택은 ");

	if (n == 1)
		printf("홀수.\n");
	else
		printf("짝수.\n");
}