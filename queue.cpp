#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include<stdio.h>
#include<string>

struct QUEUE
{
	int * buf;
	int size;
	int front;
	int back;
}queue = { {0, },-1 };

void creat_queue(const int size) {
	queue.buf = (int*)malloc(size * sizeof(int));
	queue.size = size;
	queue.front = 0;
	queue.back = 0;
}

void release_queue() {
	free(queue.buf);
	queue.size = 0;
	queue.front = 0;
	queue.back = 0;
}

bool queue_full() {
	return queue.back >= queue.size;
}

bool queue_empty() {
	return (queue.front > queue.back || queue.front > queue.size);
}
 
void enqueue(int a) {
	if (queue_full()) {
		printf("queue is full");
	}
		queue.buf[queue.back] = a;
		queue.back++;
}

int dequeue() {
	if(queue_empty()) {
		printf("queue is empty");
	}
	int val=queue.buf[queue.front];
	queue.buf[queue.front] = NULL;
	queue.front++;
	return val;
}

int main()
{
	creat_queue(10);
	enqueue(100);
	printf("enqueue[0]: %d\n",queue.buf[0]);

	enqueue(200);
	printf("enqueue[1]: %d\n", queue.buf[1]);

	enqueue(300);
	printf("enqueue[2]: %d\n", queue.buf[2]);

	enqueue(400); 
	printf("enqueue[3]: %d\n", queue.buf[3]);

	enqueue(500);
	printf("enqueue[4]: %d\n", queue.buf[4]);

	enqueue(600);
	printf("enqueue[5]: %d\n", queue.buf[5]);

	dequeue();
	dequeue();
	printf("\nafter 2 dequeue\n\n");
	for (int i = 0; i < 6; i++) {
		printf("enqueue[%d]: %d\n", i,queue.buf[i]);
	}
	release_queue();

	return 0;
}