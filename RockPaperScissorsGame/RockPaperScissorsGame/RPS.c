#include "RPS.h"

int choiceOfCom() {
	srand((unsigned)time(NULL));
	int ran = rand() % 3 + 1;
	return ran;
}

int choiceOfMe() {
	int n;
	printf("가위( 1 ), 바위( 2 ), 보( 3 ), 종료( 0 ): ");
	scanf("%d", &n);
	return n;
}

void whoIsWinner(int com, int n, int *win, int *m, int *cm, int p) {
	switch (com) {
	case 1 :
		switch (n) {
		case 1: printf("비겼습니다.\n\n"); break;
		case 2: printf("당신이 이겼습니다!!!!!!!!!!!\n\n");
					(*win)++;		 
					*m += p;
					*cm -= p;
					break;
		case 3: printf("컴퓨터가 이겼군요!\n\n");	
					*cm += p;
					*m -= p;
					break;
		default: printf("잘못 입력하셨습니다.\n\n");
		} break;
	case 2 :
		switch (n) {
		case 1: printf("컴퓨터가 이겼군요!\n\n"); 
					*cm += p;
					*m -= p;
					break;
		case 2: printf("비겼습니다.\n"); break;
		case 3: printf("당신이 이겼습니다!!!!!!!!!!!\n\n"); 
					(*win)++;	
					*m += p;
					*cm -= p;
					break;
		default: printf("잘못 입력하셨습니다.\n\n");
		} break;
	case 3 :
		switch (n) {
		case 1: printf("당신이 이겼습니다!!!!!!!!!!!\n\n"); 
					(*win)++;	
					*m += p;
					*cm -= p;
					break;
		case 2: printf("컴퓨터가 이겼군요!\n\n"); 
					*cm += p;
					*m -= p;
					break;
		case 3: printf("비겼습니다.\n");  break;
		default: printf("잘못 입력하셨습니다.\n\n");
		} break;
	}
}

void showRPS(int n) {
	switch (n) {
	case 1 :
		printf("가위\n");		break;
	case 2 :
		printf("바위\n");		break;
	case 3 :
		printf("보\n");		break;
	}
}