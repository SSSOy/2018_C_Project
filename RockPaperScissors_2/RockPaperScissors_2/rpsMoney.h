#ifndef GAMEMONEY_H
#define GAMEMONEY_H

void SetComMoney(int money);
int GetCurrentComMoney(void);

void SetYouMoney(int money);
int GetCurrentYouMoney(void);

void SetGamblingTableMoney(int money);
int SetGamblingTableMoneyByGamer(int money);
void ComWinMoneyAccount(void);
void YouWinMoneyAccount(void);

void StoreGameMoneyFromFile(fp);
void LoadGameMoneyFormFIle(fp);
#endif