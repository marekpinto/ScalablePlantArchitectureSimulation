#include <stdlib.h>
#include <linmath.h>

struct node{
	int area;
	int mass;
	int length;
	struct node *left;
	struct node *right;
	mat4x4 transformation;
};

void newNode(struct node* Node, int area, int mass, int length, mat4x4 transformation){
	Node->area = area;
	Node->mass = mass;
	Node->length = length;
	Node->left = NULL;
	Node->right = NULL;
	mat4x4_dup(Node->transformation,  transformation);	
}

int main(){
	mat4x4 rootTransformation, transformation1, transformation2, transformation3;
	newNode(struct node* root, 8, 2, 3, rootTransformation);
	newNode(root->left, 4, 2, 8, transformation1);
	newNode(root->right, 6,3 , 3, transformation2);

	newNode(root->left->left, 42, 18, 34, transformation3);

}

void breakOffNode(struct node* Node, int nodeToBreak, struct node* newRoot){
//if nodeToBreak = 0, delete left child, if 1 delete right child
	if(nodeToBreak==0){
		newRoot = Node->left;
		Node->left = NULL;
	}
	else if(nodeToBreak==1){
		newRoot = Node->right;
		Node->right = NULL;
	}
}
