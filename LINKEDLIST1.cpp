#include <stdio.h>
#include <stdlib.h>

typedef struct NODE* nd_ptr;
struct NODE
{
	int key;
	nd_ptr next;

} node[10];

int insertKey(struct NODE* head, int value, struct NODE** newhead)
{
	/* Start from head->next instead of head */
	struct NODE* p = head->next, * prev = head;
	struct NODE* new_node;
	while (p) {

		if (p->key == value) {
			printf("Key already exists...\n");
			return -1;
		}
		else if (prev->key > value) {
			new_node = (struct NODE*)malloc(sizeof(struct NODE));
			new_node->key = value;
			new_node->next = prev;
			*newhead = new_node;
			printf("Key inserted...\n");
			printf("New first node created\n");
			return 0;
		}
		else if (p->key > value) {
			new_node = (struct NODE*)malloc(sizeof(struct NODE));
			new_node->key = value;
			prev->next = new_node; /* adjust next pointers */
			new_node->next = p;
			printf("Key inserted...\n");
			return 0;
		}
		prev = p;
		p = p->next;
	}
	new_node = (struct NODE*)malloc(sizeof(struct NODE));
	new_node->key = value;
	prev->next = new_node; /* adjust next pointers */
	new_node->next = p;
	printf("Key inserted...\n");
	return 0;
}
void ScanList(struct NODE* head) {

	printf("node[0] key: %d\n",head->key);
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
}
int main() {
	node[0].key = 100;
	node[1].key = 250;
	node[2].key = 467;
	node[0].next = node[1].next = node[2].next = NULL;

	node[0].next = &node[1];
	node[1].next = &node[2];

	struct NODE* ptr = &node[0];
	struct NODE* newhead = &node[0];
	printf("//---Inserting Key : 250\n");
	insertKey(ptr, 250, &newhead);
	printf("//---Inserting Key : 300\n");
	insertKey(ptr, 300, &newhead);
	printf("//---Inserting Key : 50\n");
	insertKey(ptr, 50, &newhead);
	printf("//---Inserting Key : 500\n");
	insertKey(newhead, 500, &newhead);

	printf("\n");
	printf("Traversing the linked list...\n");
	ScanList(newhead);
	printf("Press any key to continue...\n");
	return 0;
}