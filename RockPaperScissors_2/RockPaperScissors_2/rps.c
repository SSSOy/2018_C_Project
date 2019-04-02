#include "rps.h"
#include "rpstimes.h"
#include "rpsMoney.h"
#include <time.h>
int ChoiceOfCom(void){  // 1~3 범위의 랜덤 값을 반환
	srand((unsigned int)time(NULL));
	return rand() % 3 + 1;
}

int ChoiceOfMe(void) {
	int choice;
	fputs("가위(1) 바위(2) 보(3) 종료(0) 선택? ", stdout);
	scanf("%d", &choice);
	return choice;
}

void WhoIsWinner(int com, int you) {
	int outcome = you - com;
	IncreGameTimes();

	switch (outcome){
	case 0:      /* 비길 경우 */
		puts("비겼습니다.");		
		return;
	case 1: case -2:    /* 내가 이길 경우 */
		puts("당신이 승자입니다.");
		IncreYouWinTimes();
		YouWinMoneyAccount();
		return;
	}
	puts("컴퓨터가 승자이군요!");
	ComWinMoneyAccount();
}

void ShowRSP(int rsp){ //상수에 따른 문자열(가위, 바위, 보) 출력
	switch (rsp){
	case SCISSORS:
		fputs("가위", stdout);
		break;
	case ROCK:
		fputs("바위", stdout);
		break;
	case PAPER:
		fputs("보", stdout);
		break;
	}
}