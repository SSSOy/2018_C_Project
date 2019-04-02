#include "RPS.h"

int count = 0, win = 0;
int money, cmoney;

void StoreGameTimesFromFile(fp) {
	fwrite(&count, sizeof(int), 1, fp);
	fwrite(&win, sizeof(int), 1, fp);                                                                                                                                                                                                                                                                                                                                                       
}
void LoadGameTimesFromFile(fp) {
	fread(&count, sizeof(int), 1, fp);
	fread(&win, sizeof(int), 1, fp);
}

void StoreGameMoneyFromFile(fp) {
	fwrite(&cmoney, sizeof(int), 1, fp);
	fwrite(&money, sizeof(int), 1, fp);
}
void LoadGameMoneyFromFile(fp) {
	fread(&cmoney, sizeof(int), 1, fp);
	fread(&money, sizeof(int), 1, fp);
}


void main() {
	int p;

	printf("게임머니 입력(컴퓨터는 당신과 같은 금액을 가집니다.) : ");
	scanf("%d", &money);
	cmoney = money;

	puts("");

	while (1) {
		int ran = choiceOfCom();

		printf("---------- 가위바위보 게임 시작 ----------\n\n");
		while (1) {
			printf("판돈 입력 : ");
			scanf("%d", &p);
			if (p > cmoney || p > money) {
				printf("가지고 있는 돈보다 판돈이 큽니다...'^'\n");
				continue;
			}
			break;
		}
		puts("");

		printf(">>>>> 대 결 <<<<<\n");
		int n = choiceOfMe();

		if (n == 0) {
			printf("종료합니다.'^'\n");
			break;
		}

		printf("\n>>>>> 결 과 <<<<<\n");
		whoIsWinner(ran, n, &win, &money, &cmoney, p);
		count++;

		printf("*컴퓨터의 선택은 ");
		showRPS(ran);
		printf("*당신의 선택은 ");
		showRPS(n);
		puts("");
		printf("-----> 승률 : %.0f%%\n", (win / (float)count) * 100.0);
		printf("컴퓨터의 머니 : %d원\n", cmoney);
		printf("당신의 머니 : %d원\n", money);
		printf("-----------------------------------------\n");
		if (money <= 0 || cmoney <= 0) {
			printf("\n탕진했습니다.. 파이팅!!\n\n");
			break;
		}
	}
}