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

	printf("���ӸӴ� �Է�(��ǻ�ʹ� ��Ű� ���� �ݾ��� �����ϴ�.) : ");
	scanf("%d", &money);
	cmoney = money;

	puts("");

	while (1) {
		int ran = choiceOfCom();

		printf("---------- ���������� ���� ���� ----------\n\n");
		while (1) {
			printf("�ǵ� �Է� : ");
			scanf("%d", &p);
			if (p > cmoney || p > money) {
				printf("������ �ִ� ������ �ǵ��� Ů�ϴ�...'^'\n");
				continue;
			}
			break;
		}
		puts("");

		printf(">>>>> �� �� <<<<<\n");
		int n = choiceOfMe();

		if (n == 0) {
			printf("�����մϴ�.'^'\n");
			break;
		}

		printf("\n>>>>> �� �� <<<<<\n");
		whoIsWinner(ran, n, &win, &money, &cmoney, p);
		count++;

		printf("*��ǻ���� ������ ");
		showRPS(ran);
		printf("*����� ������ ");
		showRPS(n);
		puts("");
		printf("-----> �·� : %.0f%%\n", (win / (float)count) * 100.0);
		printf("��ǻ���� �Ӵ� : %d��\n", cmoney);
		printf("����� �Ӵ� : %d��\n", money);
		printf("-----------------------------------------\n");
		if (money <= 0 || cmoney <= 0) {
			printf("\n�����߽��ϴ�.. ������!!\n\n");
			break;
		}
	}
}