#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>


bool Write_File(char fname[])
{
	FILE* pFile;
	pFile = fopen(fname, "w");

	if (pFile == NULL) 
	{
		printf("Cannot _open the file\n");
		return false;
	}

	fprintf(pFile, "%s\n", fname[i]);          
	
	fclose(pFile);
	return true;
}

bool Read_culc_File(char fname[])
{
	FILE* pFile;

	pFile = fopen(fname, "r");

	if (pFile == NULL)
	{
		printf("Cannot _open the file\n");
		return false;
	}

	char name[20];
	int avg= 0;
	int num = 0;
	int sum = 0;
	int k;
	while (fscanf(pFile, "%d ",num)!=EOF) {               
		k = num;
		for (int i = 0; i++; i < num) 
		{
			fscanf(pFile, "%d ", num);
			sum = sum + num;
		}
		printf("this group avg is %d", sum / k);

	}

	fclose(pFile);
	return true;
}

int main(int arqc, char* argv[])
{

	char num[25] = { 5 96 87 78 93 21 4 92 82 85 87 6 72 69 85 75 81 73 };
	char fname[64] = "data.txt";

	if (!Write_File(fname))
	{
		return -1;

	}

	if (!Read_culc_File(fname))
	{
		return -1;

	}

	return 0;
}