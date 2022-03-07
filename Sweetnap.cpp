#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include<stdio.h>
#include<string>

void change(int* a, int* b, int i) {
	int temp;
	temp = a[i];
	a[i] = b[i + 1];
	b[i + 1] = temp;
}

void order(int* start_hour, int* start_minute, 
	int* end_hour, int* end_minute, int num) {

	for (int i = 0; i < num-1; i++) {
		if (start_hour[i] > end_hour[i + 1]) {
			change(start_hour, end_hour,i);
			change(start_minute, end_minute, i);
		}
	}
}

void longest_nap(int* start_hour, int* start_minute, 
	int* end_hour, int* end_minute, int num) {
	int arr[MAX]= { 0 };
	int max_time=0;
	for (int i = 0; i < num-1; i++) {
		arr[i] = ((start_hour[i + 1] * 60) + start_minute[i + 1])
			-  ((end_hour[i] * 60) + end_minute[i]);
		}

	for (int i = 0; i < num - 1; i++) {
		if (arr[i] > max_time)
			max_time = i;
	}

	int hour, minute;
	hour = arr[max_time] / 60;
	minute = arr[max_time] % 60;

	if (end_minute[max_time] == 0) {
		printf("Day #1: the longest nap starts at %d:00 and \n will last for %d hours and %d minutes",
			end_hour[max_time], hour, minute);

	}
	else
	printf("Day #1: the longest nap starts at %d:%d and \nwill last for %d hours and %d minutes",
		end_hour[max_time], end_minute[max_time], hour, minute);
	
}

int main()
{
	int num;
	int start_hour[100] = { 0 };
	int end_hour[100]= { 0 };
	int start_minute[100]= { 0 };
	int end_minute[100]= { 0 };
	char task[100][100];

	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d:%d %d:%d %s", &start_hour[i], &start_minute[i], &end_hour[i], &end_minute[i], task[i]);
		if (start_hour[i] < 10 || end_hour[i] < 10 || start_hour[i] > 18 || end_hour[i] > 18 ||
			start_minute[i] < 0 || end_minute[i] < 0 || start_minute[i] > 60 || end_minute[i] > 60) {
			printf("input wrong");
			break;
		}
	}

	order(start_hour, start_minute, end_hour, end_minute, num);

	longest_nap(start_hour, start_minute, end_hour, end_minute, num);

	return 0;
}