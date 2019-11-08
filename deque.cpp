#include <stdio.h>

//link : https://github.com/jharisonn/datastructure_tutor

/* Struct Node atribut data yang bertipe integer dan mempunyai Node setelahnya yang kita namakan next
 */
struct Node{
	int data;
	Node* next;
	Node* prev;
};

struct linkedList{
	Node* head = NULL;
	Node* tail = NULL;
};

linkedList* linkedlist = new linkedList();


void push_back(int data){
	Node* node = new Node();
	node->data = data;
	node->next = NULL;
	node->prev = (linkedlist->head == NULL) ? NULL : linkedlist->tail;

	if(linkedlist->head==NULL){
		linkedlist->head = node;
		linkedlist->tail = node;

		return;
	}

	linkedlist->tail->next = node;
	linkedlist->tail = node;
}

void push_front(int data){
	Node* node = new Node();
	node->data = data;
	node->next = (linkedlist->head==NULL) ? NULL : linkedlist->head;
	node->prev = NULL;

	if(linkedlist->head==NULL){
		linkedlist->head = node;
		linkedlist->tail = node;

		return;
	}

	linkedlist->head->prev = node;
	linkedlist->head = node;
}

void pop_front(){

	if(linkedlist->head == NULL) return;

	Node* node = linkedlist->head;
	linkedlist->head = linkedlist->head->next;
	linkedlist->head->prev = NULL;
	delete node;
}

void pop_back(){
	
	if(linkedlist->head == NULL) return;
	
	Node* node = linkedlist->tail;
	linkedlist->tail = linkedlist->tail->prev;
	linkedlist->tail->next = NULL;
	
	delete node;
	
}


void display(){
	Node* node = linkedlist->head;

	while(node!=NULL){
		int data = node->data;
		printf("%d\n",data);
		node = node->next;
	}
}

void display_back(){
	Node* node = linkedlist->tail;

	while(node!=NULL){
		int data = node->data;
		printf("%d\n",data);
		node = node->prev;
	}
}

int main(){
	push_back(5);
	push_back(10);
	push_front(17);
	push_back(99);
	pop_front();
	pop_back();
	display_back();
}

