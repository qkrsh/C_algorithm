#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
	int day;
	int month;
	int year;
};

struct Store{
	int day;
	int month;
	int year;
}store[5];

void recent(struct Date day1, struct Date day2);

int main(void) {

	struct Date day1 = { 1,1,2000 };
	struct Date day2 = { 1,1,2010 };
	recent(day1, day2);
	
	struct Date day3 = { 11,11,1998 };
	struct Date day4 = { 9,25,2021 };
	recent(day3, day4);

	struct Date day5 = { 5,25,2002 };
	struct Date day6 = { 8,19,2011 };
	recent(day5, day6);

	return 0;
}

void recent(struct Date day1, struct Date day2)
{
	if (day1.year > day2.year) {
		store[0].year = day1.year;
		store[0].month = day1.month;
		store[0].day = day1.day;
	}
	else if (day1.year < day2.year) {
		store[0].year = day2.year;
		store[0].month = day2.month;
		store[0].day = day2.day;
	}
	else {
		if (day1.month > day2.month)
		{
			store[0].year = day1.year;
			store[0].month = day1.month;
			store[0].day = day1.day;
		}
		else if (day1.month < day2.month)
		{
			store[0].year = day2.year;
			store[0].month = day2.month;
			store[0].day = day2.day;
		}
		else
			if (day1.day > day2.day)
			{
				store[0].year = day1.year;
				store[0].month = day1.month;
				store[0].day = day1.day;
			}
			else if (day1.day < day2.day)
			{
				store[0].year = day2.year;
				store[0].month = day2.month;
				store[0].day = day2.day;
			}
	}
	printf("recent day is= %d / %d / %d\n", store[0].month, store[0].day, store[0].year);
}