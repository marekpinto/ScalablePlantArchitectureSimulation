#include <stdlib.h>
#include <linmath.h>

struct node{
	int area;
	int mass;
	int length;
	struct node *left;
	struct node *right;
};

struct node* newNode(int area, int mass, int length){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->area = area;
	node->mass = mass;
	node->length = length;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main(){
	struct node *root = newNode(8, 2, 3);
	root->left = newNode(4, 2, 8);
	root->right = newNode(6,3 , 3);

	root->left->left = newNode(42, 18, 34);

}
