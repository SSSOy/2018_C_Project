#define _CRT_SECURE_NO_WARNINGS
#define SUBJ 3
#include <stdio.h>
#include <stdlib.h>


char sub[5][5] = { "국어","영어","수학","C","JAVA" };

struct Student {
	char id[5];
	char name[11];
	int score[SUBJ + 1];
	float avg;
	int rank;
	char level;
};

int getLine();
void line();
void linef(FILE *result);
void input();
void printm(struct Student stTemp);
void printfile(struct Student stTemp, FILE *result);
void process(struct Student *stTemp);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int choice, pchoice;
	FILE *result = fopen("result.txt", "w");
	int getL;
	int tscore[SUBJ + 1] = { 0 };
	float tavg[SUBJ + 1] = { 0 };

	while (1) {
		struct Student *st;
		struct Student stScan;
		FILE *data;

		printf("1. 정보 입력\n2. 출력\n3. 종료\n");
		line();
		printf("메뉴 선택 : ");
		scanf("%d", &choice);
		line();

		switch(choice) {
		case 1 :
			input();
			data = fopen("data.txt", "r");
			
			fscanf(data, "%s", stScan.id);
			fscanf(data, "%s", stScan.name);
			for (int j = 0; j < SUBJ; j++) 
				fscanf(data, "%d", &stScan.score[j]);

			fclose(data);
			break;

		case 2 : 
			data = fopen("data.txt", "r");
			getL = getLine();
			if (getL == 0) {
				printf("데이터를 입력하지 않았습니다.\n");
				break;
			} //if
			printf("1. 화면 출력\n2. 파일 출력\n");
			line();
			printf("메뉴 입력 : ");
			scanf("%d", &pchoice);
			line();

			st = malloc(sizeof(struct Student) * getL);

			for (int i = 0; i < getL; i++) {
				fscanf(data, "%s", st[i].id);
				fscanf(data, "%s", st[i].name);
				for (int j = 0; j < SUBJ; j++)
					fscanf(data, "%d", &st[i].score[j]);
				process(st + i);
			} //for

			for (int i = 0; i < getL - 1; i++) {
				for (int j = i + 1; j < getL; j++) {
					if (st[i].score[SUBJ] < st[j].score[SUBJ]) 
						st[i].rank++;
					else if (st[i].score[SUBJ] > st[j].score[SUBJ])
						st[j].rank++;
				} //for
			} //for

			for (int i = 0; i < SUBJ; i++) 
				for (int j = 0; j < getL; j++) 
					tscore[i] += st[j].score[i];
			
			for (int i = 0; i < getL; i++)
				tscore[SUBJ] += st[i].score[SUBJ];

			for (int i = 0; i < SUBJ; i++)
				tavg[i] = (float)(tscore[i]) / getL;
			tavg[SUBJ] = (float)(tscore[SUBJ]) / (getL * SUBJ);

			switch (pchoice) {
			case 1 : 
				printf("\n%-7s%-10s", "학번", "이름");
				for (int i = 0; i < SUBJ; i++)
					printf("%7s", sub[i]);
				printf("%7s%9s%7s%7s\n", "총점", "평균", "등급", "석차");
				line();

				for (int i = 0; i < getL; i++) 
					printm(st[i]);
				line();

				printf("반총점");
				for (int i = 0; i < 11; i++)
					printf(" ");
				for (int i = 0; i <= SUBJ; i++) 
					printf("%7d", tscore[i]);
				puts("");
				line();

				printf("반평균");
				for (int i = 0; i < 11; i++)
					printf(" ");
				for (int i = 0; i < SUBJ; i++) 
					printf("%7.2f", tavg[i]);
				printf("       %9.2f\n\n", tavg[SUBJ]);
				line();

				fclose(data);
				break;

			case 2 :
				fprintf(result, "%-7s%-10s", "학번", "이름");
				for (int i = 0; i < SUBJ; i++)
					fprintf(result, "%7s", sub[i]);
				fprintf(result, "%7s%9s%7s%7s\n", "총점", "평균", "등급", "석차");
				linef(result);

				for (int i = 0; i < getLine(); i++)
					printfile(st[i], result);

				linef(result);
				fprintf(result, "반총점");
				for (int i = 0; i < 11; i++) 
					fprintf(result, " ");
				for (int i = 0; i <= SUBJ; i++) 
					fprintf(result, "%7d", tscore[i]);

				fprintf(result, "\n");
				linef(result);

				fprintf(result, "반평균");

				for (int i = 0; i < 11; i++) 
					fprintf(result, " ");
				for (int i = 0; i < SUBJ; i++) 
					fprintf(result, "%7.2f", tavg[i]);
				fprintf(result, "       %9.2f\n", tavg[SUBJ]);
				linef(result);

				fclose(result);
				break;

			default :
				printf("잘못 입력하셨습니다.\n\n");
			} //switch(in)
			break;
		case 3 :
			printf("종료합니다.\n\n");
			fclose(result);
			return 0;
		default :
			printf("잘못 입력하셨습니다\n\n");
		} //switch(out)
	} //while
} //main

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int getLine() {
	FILE *data = NULL;
	data = fopen("data.txt", "r");
	if (data == NULL)
		return 0;
	int count = 0;
	char temp;
	while ((temp = fgetc(data)) != EOF)
		if (temp == '\n')
			count++;
	fclose(data);
	return count;
} //getLine()

void line() {
	int data = SUBJ * 7 + 50;
	for (int i = 0; i < data; i++)
		printf("-");
	puts("");
} //line()
void linef(FILE *result) {
	int data = SUBJ * 7 + 55;
	for (int i = 0; i < data; i++)
		fprintf(result, "-");
	fprintf(result, "\n");
} //linef()

void input() {
	FILE *data = fopen("data.txt", "a");
	if (data == NULL) {
		printf("파일이 존재하지 않습니다. 파일을 만들고 다시 시도해 주세요.");
		exit(0);
	} //if
	struct Student stTemp;
	printf("학번 입력 : ");
	scanf("%s", stTemp.id);
	fprintf(data, "%-7s", stTemp.id);

	printf("이름 입력 : ");
	scanf("%s", stTemp.name);
	fprintf(data, "%-10s", stTemp.name);

	for (int j = 0; j < SUBJ; j++) {
		while (1) {
			printf("%s점수 입력 : ", sub[j]);
			scanf("%d", &stTemp.score[j]);
			if (stTemp.score[j] > 100 || stTemp.score[j] < 0)
				printf("%s 에러\n", sub[j]);
			else {
				fprintf(data, "%7d", stTemp.score[j]);
				break;
			} //else
		}//while
	}//for
	fprintf(data, "\n");
	line();
	fclose(data);
} //input()

void printm(struct Student stTemp) {
	printf("%-7s%-10s", stTemp.id, stTemp.name);
	for (int j = 0; j < SUBJ + 1; j++)
		printf("%7d", stTemp.score[j]);
	printf("%9.2f%7c%7d\n", stTemp.avg, stTemp.level, stTemp.rank);
} //printm()
void printfile(struct Student stTemp, FILE *result) {
	fprintf(result, "%-7s%-10s", stTemp.id, stTemp.name);
	for (int j = 0; j < SUBJ + 1; j++)
		fprintf(result, "%7d", stTemp.score[j]);
	fprintf(result, "%9.2f%7c%7d\n", stTemp.avg, stTemp.level, stTemp.rank);
} //printfile()

void process(struct Student *stTemp) {
	stTemp->rank = 1;
	stTemp->score[SUBJ] = 0;

	for (int j = 0; j < SUBJ; j++)
		stTemp->score[SUBJ] += stTemp->score[j];
	stTemp->avg = (float)stTemp->score[SUBJ] / SUBJ;

	switch ((int)(stTemp->avg / 10)) {
	case 10: case 9:
		stTemp->level = 'A'; break;
	case 8:
		stTemp->level = 'B'; break;
	case 7:
		stTemp->level = 'C'; break;
	case 6:
		stTemp->level = 'D'; break;
	default:
		stTemp->level = 'E';
	}//switch
} //process
