#ifndef GAMETIMES_H
#define GAMETIMES_H
void IncreGameTimes(void);
int GetGameTimes(void);

void IncreYouWinTimes(void);
int GetYouWinTimes(void);

int GetPercenOfVictory(void);

void StoreGameTimesFromFile(fp);
void LoadGameTimesFromFile(fp);
#endif
