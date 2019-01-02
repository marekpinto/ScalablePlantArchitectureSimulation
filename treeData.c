#include <stdlib.h>
#include "linmath.h"

typedef struct Node{
				int area;
				int mass;
				int length;
				struct Node *left;
				struct Node *right;
				mat4x4 transformation;
} Node;

void newNode(Node* pNode, Node* pLeftNode, Node* pRightNode, const int area, const int mass, const int length, mat4x4 transformation){
				pNode->area = area;
				pNode->mass = mass;
				pNode->length = length;
				pNode->left = pLeftNode;
				pNode->right = pRightNode;
				mat4x4_dup(pNode->transformation, transformation);	
}


int main(){
				mat4x4 rootTransformation;
				mat4x4 transformation1;
				mat4x4 transformation2;
				mat4x4 transformation3;
				Node root;
				Node left;
				Node right;
				Node leftRight;

				newNode(&root, &left, &right, 8, 2, 3, rootTransformation);
				newNode(&left, NULL, &leftRight, 4, 2, 8, transformation1);
				newNode(&right, NULL, NULL, 6,3 , 3, transformation2);

				//breaking this off into new tree
				//break off right node

}

