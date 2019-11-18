#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* pushTree(struct Node* tree, int data){
	if(tree == NULL){
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;

		return node;
	}

	if(data < tree->data){
		tree->left = pushTree(tree->left, data);
	}
	else{
		tree->right = pushTree(tree->right,data);
	}

	return tree;

}

void preOrder(struct Node* tree){
	if(tree==NULL) return;

	printf("%d\n", tree->data);
	preOrder(tree->left);
	preOrder(tree->right);
}

void inOrder(struct Node* tree){
	if(tree==NULL) return;

	inOrder(tree->left);
	printf("%d\n", tree->data);
	inOrder(tree->right);
}

void postOrder(struct Node* tree){
	if(tree==NULL) return;

	postOrder(tree->left);
	postOrder(tree->right);
	printf("%d\n", tree->data);
}

int main(){
	struct Node* tree = NULL;
	int n;
	scanf("%d",&n);
	while(n--){
		int data;
		scanf("%d",&data);
		tree = pushTree(tree, data);
	}
	printf("preOrder\n");
	preOrder(tree);

	printf("inOrder\n");
	inOrder(tree);

	printf("postOrder\n");
	postOrder(tree);


	return 0;
}
