#ifndef Game_H
#define Game_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int choiceOfCom();
int choiceOfMe();
void whoIsWinner(int com, int n, int *win, int *money, int p);
void showRPS(int n);

#endif