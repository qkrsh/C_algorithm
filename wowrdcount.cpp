#include <stdio.h>
#define max 5

int word_count(char text[])
{
	int cnt = 0;
	int i = 0;
	while (text[i] != '/0') {
		if (text[i] == ' ') {
			cnt++;
		}
		i++;
	}
	return cnt;
}

int main()
{
	int count;
	char test1[] = "Hello world!";
	count = word_count(test1);
	printf("count(%s) : % d\n", test1, count);

		return 0;
}
