#include "RPS.h"

int choiceOfCom() {
	srand((unsigned)time(NULL));
	int ran = rand() % 3 + 1;
	return ran;
}

int choiceOfMe() {
	int n;
	printf("����( 1 ), ����( 2 ), ��( 3 ), ����( 0 ): ");
	scanf("%d", &n);
	return n;
}

void whoIsWinner(int com, int n, int *win, int *m, int *cm, int p) {
	switch (com) {
	case 1 :
		switch (n) {
		case 1: printf("�����ϴ�.\n\n"); break;
		case 2: printf("����� �̰���ϴ�!!!!!!!!!!!\n\n");
					(*win)++;		 
					*m += p;
					*cm -= p;
					break;
		case 3: printf("��ǻ�Ͱ� �̰屺��!\n\n");	
					*cm += p;
					*m -= p;
					break;
		default: printf("�߸� �Է��ϼ̽��ϴ�.\n\n");
		} break;
	case 2 :
		switch (n) {
		case 1: printf("��ǻ�Ͱ� �̰屺��!\n\n"); 
					*cm += p;
					*m -= p;
					break;
		case 2: printf("�����ϴ�.\n"); break;
		case 3: printf("����� �̰���ϴ�!!!!!!!!!!!\n\n"); 
					(*win)++;	
					*m += p;
					*cm -= p;
					break;
		default: printf("�߸� �Է��ϼ̽��ϴ�.\n\n");
		} break;
	case 3 :
		switch (n) {
		case 1: printf("����� �̰���ϴ�!!!!!!!!!!!\n\n"); 
					(*win)++;	
					*m += p;
					*cm -= p;
					break;
		case 2: printf("��ǻ�Ͱ� �̰屺��!\n\n"); 
					*cm += p;
					*m -= p;
					break;
		case 3: printf("�����ϴ�.\n");  break;
		default: printf("�߸� �Է��ϼ̽��ϴ�.\n\n");
		} break;
	}
}

void showRPS(int n) {
	switch (n) {
	case 1 :
		printf("����\n");		break;
	case 2 :
		printf("����\n");		break;
	case 3 :
		printf("��\n");		break;
	}
}