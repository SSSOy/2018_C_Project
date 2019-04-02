#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "rpstimes.h"
#include "rpsMoney.h"

#define FILE_NAME "gamefile.dat"
#define FILE_NAME_DEL "del gamefile.dat"

int DoYouWantToContinue() {
	FILE *fp;
	int cont;

	if (!AvailContinue()) return 0; //파일이 존재하면

	puts("게임을 이어서 하시겠습니까?(Yes:1, No:0)");
	scanf("%d", &cont);

	if (cont == 0) return 0;

	fp = fopen(FILE_NAME, "rb"); //파일 읽기 모드
	if (fp == NULL) {
		puts("이어서 할 데이터가 존재하지 않습니다");
		return 0;
	}
	LoadGameTimesFromFile(fp); //게임 승리 정보
	LoadGameMoneyFormFIle(fp); //게임 머니 정보
	fclose(fp);
	return 1;
}
int DoYouWantToStore() {
	FILE *fp;
	int cont;
	puts("게임 내용을 저장하시겠습니까?(Yes:1, No:0)");
	scanf("%d", &cont);

	if (cont == 0) return 0;
	fp = fopen(FILE_NAME, "wb");//파일 쓰기 모드
	StoreGameTimesFromFile(fp);
	StoreGameMoneyFromFile(fp);

	fclose(fp);
	return 1;
}
int AvailContinue() { // 게임을 이어서 할 데이터가 존재하면
	FILE *fp;
	fp = fopen(FILE_NAME, "rb"); //파일 읽기 모드
	if (fp == NULL) return 0;
	else {
		fclose(fp);
		return 1;
	}
}
void ClearContinueInfo() {
	FILE *fp;
	fp = fopen(FILE_NAME, "rb");

	if (fp != NULL) {
		fclose(fp);
		system(FILE_NAME_DEL);
	}
}