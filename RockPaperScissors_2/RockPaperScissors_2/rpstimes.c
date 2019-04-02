#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int gameNumOfTimes = 0;
static int youWinNumOfTimes = 0;

void StoreGameTimesFromFile(fp) {
	fwrite(&gameNumOfTimes, sizeof(int), 1, fp);
	fwrite(&youWinNumOfTimes, sizeof(int), 1, fp);
}
void LoadGameTimesFromFile(fp) {
	fread(&gameNumOfTimes, sizeof(int), 1, fp);
	fread(&youWinNumOfTimes, sizeof(int), 1, fp);
}

void IncreGameTimes(void){ //게임 실행 수 증가
	gameNumOfTimes++;
}
int GetGameTimes(void){//게임 실행 수 반
	return gameNumOfTimes;
}
void IncreYouWinTimes(void){
	youWinNumOfTimes++;
}
int GetYouWinTimes(void){//게이머의 게임 우승 수 반환
	return youWinNumOfTimes;
}
int GetPercenOfVictory(void){ //게이머의 승률 계산
	if (gameNumOfTimes == 0)
		return 0;	
	
	return (double)youWinNumOfTimes / gameNumOfTimes * 100;
}
