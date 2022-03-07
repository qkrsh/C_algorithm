#include <stdio.h>
#include <stdlib.h>

typedef struct Elephant {
	int id;
	int weight;
	int iq;
} eleph;

eleph elephant[1000];
eleph temp;
int lcs[1000];
int begin[1000];

void dpprint(int idx) {
	if (idx == -1)
		return;
	dpprint(from[idx]);
	printf("%d\n", elephant[idx].id);
}

//smart elephant
int main() {
	int ele = 0;
	int maxidx, max = -1;
	int we, iq;

	//if enter (-1 -1), EOF
	while (1) {
		scanf("%d %d", &we, &iq);
		if (we == EOF)
			break;
		elephant[ele].weight = we;
		elephant[ele].iq = iq;
		elephant[ele].id = ele + 1;
		ele++;
	}
	int n = ele;

	//Ascending sort
	//If weight is equal, iq sort ascending. 
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n - 1;j++) {
			if (elephant[j].weight == elephant[j + 1].weight)
			{
				if (elephant[j].iq > elephant[j + 1].iq)
				{
					temp = elephant[j];
					elephant[j] = elephant[j + 1];
					elephant[j + 1] = temp;
				}
			}
			if (elephant[j].weight > elephant[j + 1].weight)
			{
				temp = elephant[j];
				elephant[j] = elephant[j + 1];
				elephant[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		lcs[i] = 1;
		begin[i] = -1;
		for (int j = 0; j < i; j++) {
			if (elephant[i].iq < elephant[j].iq && lcs[i] < lcs[j] + 1) {
				lcs[i] = lcs[j] + 1;
				begin[i] = j;
				if (max < lcs[i]) {
					max = lcs[i];
					maxidx = i;
				}
			}
		}
	}

	//print langth
	//print Output
	printf("\n%d\n",maxidx);
	for (int i =maxidx; i <= 0; i--) {
		if (idx == -1)
			return;
		if (begin[i] != -1) {
			printf("%d\n", elephant[begin[i]].id);
		}
	}
	printf("%d\n",elephant[maxidx].id);

}

/*
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
- 1 - 1
*/