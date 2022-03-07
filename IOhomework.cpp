#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>

bool Write_File(char fname[])
{
	FILE* pFile;
	pFile = fopen(fname, "w");

	char num[100] = {"5 96 87 78 93 21 4 92 82 85 87 6 72 69 85 75 81 73"};

	if (pFile == NULL)
	{
		printf("Cannot _open the file\n");
		return false;
	}

	fprintf(pFile, "%s\n", num);

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
	int gr;
	double sum = 0;
	int k;
	int q;

	while (fscanf(pFile, "%d", &gr) != EOF) 
	{
		for (int i = 0; i < gr; i++) {
			fscanf(pFile, "%d", &q);
			sum = sum + q;
		}
		double avg = sum / gr;
		printf("this group avg is %.2f\n", avg);
		sum = 0;
	}

	fclose(pFile);
	return true;
}

int main(int arqc, char* argv[])
{

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