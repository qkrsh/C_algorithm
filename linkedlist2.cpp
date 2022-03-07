#include <stdio.h>
#include <stdlib.h>

typedef struct NUM* num_ptr;
struct NUM
{
	int key;
	num_ptr next;

} num[10];

int insertKey(struct NUM* head, int nums, struct NUM** newhead)
{
	/* Start from head->next instead of head */
	struct NUM* p = head->next, * prev = head;
	struct NUM* new_node;
	while (p) {

		if (p->key > nums) {
			break;
		}
		prev = p;
		p = p->next;
	}
	new_node = (struct NUM*)malloc(sizeof(struct NUM));
	new_node->key = nums;
	prev->next = new_node; /* adjust next pointers */
	new_node->next = p;
	return 0;
}

void ScanList(struct NUM* head) {
	head = head->next;
	printf("node[0] key: %d\n", head->key);
	head = head->next;
	printf("node[1] key: %d\n", head->key);
	head = head->next;
	printf("node[2] key: %d\n", head->key);
	head = head->next;
	printf("node[3] key: %d\n", head->key);
	head = head->next;
	printf("node[4] key: %d\n", head->key);
	head = head->next;
	printf("node[5] key: %d\n", head->key);
	head = head->next;
	printf("node[6] key: %d\n", head->key);
	head = head->next;
	printf("node[7] key: %d\n", head->key);
	head = head->next;
	printf("node[8] key: %d\n", head->key);
	head = head->next;
	printf("node[9] key: %d\n", head->key);
}

void ClearList(struct NUM* head) {
	printf("node[0] deleted\n");
	struct NUM* temp;
	temp = head;
	head = head->next;
	printf("node[1] deleted\n");
	struct NUM* temp2;
	temp2 = head;
	head = head->next;
	free(temp2);
	printf("node[2] deleted\n");
	struct NUM* temp3;
	temp3 = head;
	head = head->next;
	free(temp3);
	printf("node[3] deleted\n");
	struct NUM* temp4;
	temp4 = head;
	head = head->next;
	free(temp4);
	printf("node[4] deleted\n");
	struct NUM* temp5;
	temp5 = head;
	head = head->next;
	free(temp5);
	printf("node[5] deleted\n");
	struct NUM* temp6;
	temp6 = head;
	head = head->next;
	free(temp6);
	printf("node[6] deleted\n");
	struct NUM* temp7;
	temp7 = head;
	head = head->next;
	free(temp7);
	printf("node[7] deleted\n");
	struct NUM* temp8;
	temp8 = head;
	head = head->next;
	free(temp8);
	printf("node[8] deleted\n");
	struct NUM* temp9;
	temp9 = head;
	head = head->next;
	free(temp9);
	printf("node[9] deleted\n");

}
int main() {

	int nums[10] = { 17,39,11,9,42,12,15,8,13,41 };

	struct NUM* ptr = &num[0];
	struct NUM* newhead = &num[0];

	for (int i = 0; i < 10; i++) {
		printf("//---Inserting Key : %d\n", nums[i]);
		insertKey(ptr, nums[i], &newhead);
		printf("[%d] elements. Key inserted...\n",i+1);
	}
	printf("\n");

	printf("Traversing the linked list...\n");
	ScanList(newhead);

	struct NUM* temp;
	temp = newhead->next;

	printf("\nDeleting the linked list...\n");
	ClearList(newhead);

	printf("Press any key to continue...\n");

	return 0;
}