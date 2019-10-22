#include <stdio.h>

struct Node{
	int data;
	Node* next;
};

struct Stack{
	int size=0;
	Node* head;
};

Stack* stack = new Stack();

void push_back(int data){
	Node* node = new Node();
	node->data = data;
	node->next = (stack->head == NULL) ? NULL : stack->head;

	stack->head = node;
	stack->size += 1;


}

void pop_back(){
	if(stack->head == NULL) return;

	Node* node = stack->head;
	stack->head = stack->head->next;

	delete node;
	stack->size -=1;

}

void display(){
	Node* node = stack->head;

	while(node != NULL){
		int data = node->data;
		printf("%d\n", data);
		node = node->next;
	}
}

int main(){
	push_back(5);
	push_back(10);
	pop_back();

	push_back(15);
	display();
}
