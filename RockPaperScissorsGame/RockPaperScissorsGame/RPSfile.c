#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "gameFile.dat"
#define FILE_NAME_DEL "del gameFile.dat"

int DoYouWantToContinue() {
	FILE *fp;
	int cont;

	if (!AvailContinue()) return 0;

	printf("게임을 이어서 하시겠습니까? (Yes - 1, No - 0) : ");
	scanf("%d", &cont);

	if (cont == 0) return 0;

	fp = fopen(FILE_NAME, "rb");
	if (fp == NULL) {
		puts("이어서 할 데이터가 존재하지 않습니다.\n");
		return 0;
	}
	LoadGameTimesFromeFile(fp);
	LoadGameFromFile(fp);

	fclose(fp);
	return 1;
}

int DoYouWantToStore() {
	FILE *fp;
	int cont;

	printf("게임을 저장하시겠습니까? (Yes - 1, No - 0) : ");
	scanf("%d", &cont);
	if (cont == 0) return 0;

	fp = fopen(FILE_NAME, "wb");
	StoreGameTimesFromeFile(fp);
	StoreGameMoneyFromFile(fp);

	fclose(fp);
	return 1;
}

int AvailContinue() {
	FILE *fp = fopen(FILE_NAME, "rb");
	if (fp == NULL) return 0;
	else {
		fclose(fp);
		return 1;
	}
}

void ClearContinueInfo() {
	FILE *fp = fopen(FILE_NAME, "rb");
	
	if (fp != NULL) {
		fclose(fp);
		system(FILE_NAME_DEL);
	}
}