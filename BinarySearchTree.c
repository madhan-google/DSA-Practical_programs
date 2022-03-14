#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node* right;
	struct Node* left;
};
struct Node* create(int val){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->val = val;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}
struct Node* insert(struct Node* root, int val){
	if(root == NULL){
		return create(val);
	}else{
		if(root->val>=val){
			root->left = insert(root->left, val);
		}else{
			root->right = insert(root->right, val);
		}
	}
	return root;
}
void preorder(struct Node* root){
	if(root != NULL){
		printf("%d ", root->val);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct Node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->val);
		inorder(root->right);
	}
}
void postorder(struct Node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->val);
	}
}
// int search(struct Node *root, int target){
// 	if(root == NULL) return 0;
// 	if(root->val == target) return 1;
// 	return search(root->left, target) || search(root->right, target);
// }
// int findMax(struct Node *root){
// 	struct Node* cur = root;
// //	int mx = cur->val;
// 	while(cur!=NULL) cur = cur->right;
// 	return cur->val;
// }
// int height(struct Node* root){
// 	if(root is NULL) return 0;
// 	int l = height(root->left);
// 	int r = height(root->right);
// 	return l>r?l+1:r+1;
// }
// int diameter(struct Node* root){
// 	if(root is NULL) return 0;
// 	return 1 + (height(root->left) + height(root->right));
// }
int main()
{
	struct Node* root = NULL;
	int n;
	scanf("%d", &n);
	printf("\nenter the elements: ");
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		root = insert(root, num);
	}
	printf("PREORDER\n");
	preorder(root);
	printf("\n");
	printf("INORDER\n");
	inorder(root);
	printf("\n");
	printf("postORDER\n");
	postorder(root);
}

















