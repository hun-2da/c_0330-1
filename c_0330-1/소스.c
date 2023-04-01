#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10

typedef struct{
	int stack[MAX_SIZE];
	int top;
}element;
element e = { {-1}, -1};

int is_empty() {
	return (e.top == -1);
}
int is_full() {
	return (e.top == (MAX_SIZE - 1));
}
void push(int item) {
	if (is_full()) {
		fprintf(stderr, "stack full\n");
		return;
	}
	else e.stack[++e.top] = item;
}
int pop() {
	if (is_empty()) {
		fprintf(stderr, "stack empty\n");
		return -1;
	}
	else return e.stack[e.top--];
}
int main() {
	srand(time(NULL));
	printf("----Using array----\n");
	for (int i = 1; i <= MAX_SIZE * 3; i++) {

		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 1) {
			printf("[%3d]pop %d\n", i, pop());
			
		}
		else {
			printf("[%3d]push %d\n", i, rand_num);
			push(rand_num);

		}
	}
}