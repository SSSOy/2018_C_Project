#include <stdio.h>
#include <stdlib.h>

static int moneyCom;  // 컴퓨터 소유 머니
static int moneyYou;  // 게이머 소유 머니
static int gamblingTableMoney;

void StoreGameMoneyFromFile(fp) {
	fwrite(&moneyCom, sizeof(int), 1, fp);
	fwrite(&moneyYou, sizeof(int), 1, fp);
}
void LoadGameMoneyFormFIle(fp) {
	fread(&moneyCom, sizeof(int), 1, fp);
	fread(&moneyYou, sizeof(int), 1, fp);
}

void SetComMoney(int money){
	if (money < 0)	{// 에러를 알리기 위한 메시지 출력 생략.
		return;
	}
	moneyCom = money;
}

int GetCurrentComMoney(void){
	return moneyCom;
}

void SetYouMoney(int money){
	if (money < 0)	{// 에러를 알리기 위한 메시지 출력 생략.
		return;
	}
	moneyYou = money;
}

int GetCurrentYouMoney(void){
	return moneyYou;
}

void SetGamblingTableMoney(int money){
	if (money < 0)
		gamblingTableMoney = 0;
	else
		gamblingTableMoney = money;
}

void ComWinMoneyAccount(void){
	moneyYou -= gamblingTableMoney;
	moneyCom += gamblingTableMoney;
}

void YouWinMoneyAccount(void){
	moneyCom -= gamblingTableMoney;
	moneyYou += gamblingTableMoney;
}

int SetGamblingTableMoneyByGamer(int money){
	if (money > moneyYou)
		return 0;   // gamer 소유 금액 초과
	else if (money > moneyCom)
		return -1;  // com 소유 금액 초과

	SetGamblingTableMoney(money);
	return 1;  // 정상적 입력.
}