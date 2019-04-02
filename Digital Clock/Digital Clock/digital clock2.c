#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {
	time_t now;
	struct tm *d;
	time(&now);

	now = time(NULL);
	d = localtime(&now);

	printf("현재 날짜와 시간 : %s\n", asctime(localtime(&now)));
	printf("현재 날짜와 시간 : %s\n", ctime(&now));

	printf("현재 날짜 : %d년 %d월 %d일\n", d->tm_year + 1900, d->tm_mon + 1, d->tm_mday);
	printf("현재 시간 : %d시 %d분 %d초\n", d->tm_hour, d->tm_min, d->tm_sec);
}
