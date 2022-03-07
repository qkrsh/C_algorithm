#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>


struct EMPLOYEE {
	char name[20];
	char name2[20];
	int id;
	double salary;
	char date[20];
} ;

bool Create_File(char fname[])
{
	struct EMPLOYEE emp[5];

	emp[0] = { "Anthony", "A.J.", 10031, 7.82, "12 / 18 / 62" };
	emp[1] = { "Burrows", "W.K.", 10067, 9.14, "6 / 9 / 63" };
	emp[2] = { "Fain", "B.D.", 10083, 8.79, "5 / 18 / 59" };
	emp[3] = { "Janney", "P.", 10095, 10.57, "9 / 28 / 62" };
	emp[4] = { "Smith", "G.J.", 10105, 8.50, "12 / 20 / 61" };

	FILE* pFile = NULL;
	pFile = fopen(fname, "w");

	if (pFile == NULL) 
	{
		printf("Cannot open the file\n");
		return false;
	}

	for (int i = 0; i < 5; i++) {
		fprintf(pFile, "%s %s %d %lf %s \n", emp[i].name, emp[i].name2, emp[i].id, emp[i].salary, emp[i].date);     //fprintf를 이용해서 스트럭쳐에 있는 것을 pFile에 출력저장
	}

	return true;
}

bool fcopy(char * a, char *b) {

	FILE* pIn = NULL;
	FILE* pOut = NULL;

	pIn = fopen(a, "r");
	if (pIn == NULL)
	{
		printf("Cannot open the file\n");
		return false;
	}

	pOut = fopen(b, "w");
	if (pOut == NULL)
	{
		printf("Cannot open the file\n");
		return false;
	}

	char ch;
	while((ch = fgetc(pIn)) != EOF)              // pIn파일이 끝날때까지 ch로 하나씩 가져와서 pOut에 저장하기
	{
		fputc(ch, pOut);
	}

	fclose(pIn);
	fclose(pOut);

	return true;

}

int main(int arqc, char* argv[])
{


	struct EMPLOYEE;
	
	char fname[64] = "employee.txt";
	char fname2[64] = "employee2.txt";

	if (!Create_File(fname))
	{
		return -1;
	}

	if (!fcopy(fname, fname2))
	{
		return -1;
	}

	char src[50];
	char dest[50];
	printf("Type source destinatiln file name!!\n");

		scanf("%s %s", &src, &dest);

	if (!fcopy(src, dest))
	{
		return -1;
	}




	return 0;
}