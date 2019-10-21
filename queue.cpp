#include <stdio.h>

/*
 * Menurut dari sumber http://www.cplusplus.com/reference/queue/queue
 * Queue mempunyai fungsi
 * empty, size, front, back, push_back, pop_front
 * 1. fungsi empty sendiri gunanya untuk mengecek apakah Queue kosong atau tidak. (Boolean)
 * 2. fungsi size sendiri gunanya untuk mereturn besar size dari queue sendiri. (integer)
 * 3. front sendiri untuk mereturn data yang ada di head.
 * 4. back sendiri untuk mereturn data yang ada di tail.
 * 5. push_back untuk menaruh data di belakang queue.
 * 6. pop_front untuk menghilangkan data yang ada di head.
 */

struct Node{
	int data;
	Node* next;
};

struct Queue{
	int size = 0;
	Node* head;
	Node* tail;
};

Queue* queue = new Queue();

void push_back(int data){
	Node* node = new Node();
	node->data = data;
	node->next = NULL;

	queue->size += 1;

	if(queue->head == NULL){

		queue->head = node;
		queue->tail = node;

		return;
	}

	queue->tail->next = node;
	queue->tail = node;
}

void pop_front(){

	if(queue->head == NULL) return;

	Node* node = queue->head;
	queue->head = queue->head->next;
	queue->size -= 1;
	delete node;
}

void display(){
	Node* node = queue->head;
	while(node!=NULL){
		int data = node->data;
		printf("%d\n",data);
		node = node->next;
	}
}

int main(){
	push_back(5);
	push_back(10);
	pop_front();

	push_back(12);

	display();

	printf("Queue size : %d\n", queue->size);
}
