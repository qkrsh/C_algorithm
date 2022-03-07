#include <stdio.h>

int word_count(char text[])
{
	int cnt = 0;
	char prev, cur;
	int i = 0;
	cur = text[i];
	prev = ' ';
	while (text[i] != '\0') 
	{
		if (prev == ' ' && cur != ' ') 
		{
				cnt++;
		}
			prev = cur;
			i = i + 1;
		}
	return cnt;
}

int main()
{
	int count;
	char test1[] = "  Hello   world! c";
	count = word_count(test1);
	if (test1[1] != '\0') {
		count=count+1;
	}
	printf("count(%s) : %d", test1, count);

	return 0;
}
