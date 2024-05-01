#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack {
	int top;
	unsigned int capacity;
	int* array;
};


struct stack* createStack(int _capacity) {
	struct stack* yeniYigin = (struct stack*)malloc(sizeof(struct stack));
	yeniYigin->capacity = _capacity;
	yeniYigin->top = -1;
	yeniYigin->array = (int*)malloc(sizeof(int) * yeniYigin->capacity);
	return yeniYigin;
}

int isEmpty(struct stack* yigin) {
	return yigin->top == -1;
}
int isFull(struct stack* yigin) {
	return yigin->top == yigin->capacity - 1;
}

void push(struct stack* yigin, int x) {
	if (isFull(yigin)) {
		return;
	}
	yigin->array[++yigin->top] = x;
}
int pop(struct stack* yigin) {
	if (isEmpty(yigin)) {
		return INT_MIN;
	}
	
	return yigin->array[yigin->top--];

}

int evPos(char* exp) {
	struct stack* yigin = createStack(strlen(exp));
	 int i= strlen(exp)-1;
	 //printf("%d\n", i);
	 for (; i >= 0;i--) {
		 if (isdigit(exp[i])) {
			 push(yigin, exp[i] - '0');
		 }
		 else {
			 int veri1 = pop(yigin);
			 int veri2 = pop(yigin);
			 switch (exp[i])
			 {
				 case '+':
					 push(yigin, veri2 + veri1);
					 break;
				 case '-':
					 push(yigin, veri2 - veri1);
					 break;
				 case '/':
					 push(yigin, veri2 / veri1);
					 break;
				 case '*':
					 push(yigin, veri2 * veri1);
					 break;
				 
			 }
		 }
	 }
	 return pop(yigin);
}
int main() {
	char* veriler = "/3+6*23";
	char* veriler2 = "(*2)+(3/1)+8";
	printf("sonuc = %d\n", evPos(veriler));
	return 0;
}