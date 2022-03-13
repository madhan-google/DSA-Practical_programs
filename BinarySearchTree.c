#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//#include<bits/c++>
#define sf scanf
#define pf printf
#define nl pfs("\n");
#define VD void
#define pb push_back
#define pfn(n) printf("%d", n);
#define pff(n) printf("%f", n);
#define pfd(n) printf("%lf", n);
#define pfc(ch) printf("%c", ch);
#define pfs(s) printf("%s", s);
#define sff(f) sf("%f", &f);
#define sfn(n) sf("%d", &n);
#define sfc(ch) sf("%c", &ch);
#define sfs(s) gets(s);
#define fl float
#define dd double
#define sz(x) (int)x.size();
#define max(a, b) a>b?a:b
#define min(a, b) a>b?b:a
#define INF while(1)
#define WHL(i, n) while(i<n)
#define WHL while
#define FOR(i, s, e, c) for(i=(s);i<(e); i+=(c))
#define BR break;
#define CNT continue;
#define _ pfs(" ");
#define __ pfs("\t");
#define PER(n, p) (n*(p/100.0))
#define or ||
#define and &&
#define is ==
#define isnot !=
#define $ auto
//#define EACH(x, ar) for(auto& (x) : (ar))
//int mx;
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
	if(root==NULL){
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
VD preorder(struct Node* root){
	if(root!=NULL){
		pfn(root->val) _
		preorder(root->left);
		preorder(root->right);
	}
}
VD inorder(struct Node *root){
	if(root!=NULL){
		inorder(root->left);
		pfn(root->val) _
		inorder(root->right);
	}
}
VD postorder(struct Node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		pfn(root->val) _
	}
}
int search(struct Node *root, int target){
	if(root==NULL) return 0;
	if(root->val==target) return 1;
	return search(root->left, target) || search(root->right, target);
}
int findMax(struct Node *root){
	struct Node* cur = root;
//	int mx = cur->val;
	WHL(cur!=NULL) cur = cur->right;
	return cur->val;
}
int height(struct Node* root){
	if(root==NULL) return 0;
	int l = height(root->left);
	int r = height(root->right);
	return l>r?l+1:r+1;
}
int diameter(struct Node* root){
	if(root==NULL) return 0;
	return 1 + (height(root->left) + height(root->right));
}
int main()
{
	struct Node* root = NULL;
	root = insert(root, 9);
	root = insert(root, 11);
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 20);
	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 10);
	pfs("preorder") nl
	preorder(root);
	pfs("\ninorder") nl
	inorder(root);
	pfs("\npost order") nl
	postorder(root);
	nl
	pfs(search(root,0)==1?"found":"not found");
	nl
//	list<int> li;
	pf("diameter : %d", diameter(root));
}

















