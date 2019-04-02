#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { EXIT=0,SCISSORS, ROCK, PAPER };
/* 가위 SCISSORS, 바위 ROCK, 보 PAPER */
int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);
void ShowRSP(int rsp);

#endif
