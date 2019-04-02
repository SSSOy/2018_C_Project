#include "rps.h"
#include "rpstimes.h"
#include "rpsMoney.h"
#include "rpsFile.h"

int main(void){
	int com;
	int you;

	int youMoney;
	int tableMoney;
	int ret;

	if (!DoYouWantToContinue())	{
		puts("-----가위 바위 보 게임 시작-----");
		puts("");

		SetComMoney(5000);

		fputs("▶ 당신의 게임 머니 입력 : ", stdout);
		scanf("%d", &youMoney);
		if (youMoney <= 0)
		{
			puts("적절치 못한 입력으로 프로그램을 종료합니다.");
			return -1;
		}
		SetYouMoney(youMoney);
	}
	printf("◈ 당신의 게임 머니: %d \n", GetCurrentYouMoney());
	printf("▣ 컴퓨터 게임 머니: %d \n\n", GetCurrentComMoney());

	while (1)
	{
		puts("▶ 판돈 설정!◀");
		fputs("▷ 판돈 입력: ", stdout);
		scanf("%d", &tableMoney);
		puts("");

		ret = SetGamblingTableMoneyByGamer(tableMoney);
		if (ret == 0 || ret == -1)  // 판돈 입력 오류!
		{
			if (ret == 0) // 사용자 소유 금액 초과
			{
				puts("소유하고 있는 금액 내에서 거세요!");
				printf("◈ 당신의 현재 게임 머니: %d \n", GetCurrentYouMoney());
			}
			else // 컴퓨터 소유 금액 초과
			{
				puts("컴퓨터 소유 금액 초과입니다!");
				printf("▣ 컴퓨터의 현재 게임 머니: %d \n", GetCurrentComMoney());
			}
			continue;
		}

		puts("▷▷▷▷▷ 대  결 ◁◁◁◁◁");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		puts("");

		if (you == EXIT)	break;

		puts("▶▶▶▶▶ 결  과 ◀◀◀◀◀");
		WhoIsWinner(com, you);

		fputs("▣ 컴퓨터의 선택: ", stdout);
		ShowRSP(com);
		puts("");

		fputs("◈ 당신의 선택: ", stdout);
		ShowRSP(you);
		puts("");

		printf("---> 승률 : %d %% \n\n", GetPercenOfVictory());
		printf("◈ 당신의 머니: %d \n", GetCurrentYouMoney());
		printf("▣ 컴퓨터 머니: %d \n\n", GetCurrentComMoney());

		if (GetCurrentComMoney() <= 0 || GetCurrentYouMoney() <= 0)
			break;
	}
	puts("♣♣♣♣♣ 최 종 결 과 ♣♣♣♣♣");
	printf("최종승률 : %d %% \n", GetPercenOfVictory());

	if (GetCurrentComMoney() != 0 && GetCurrentYouMoney() != 0)
		DoYouWantToStore();  // 게임내역 저장.
	else
		ClearContinueInfo();

	puts("Thank You~ See you Again~~~!");
	puts("");

	return 0;
}