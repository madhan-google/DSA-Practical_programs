#include<stdio.h>
#include<stdlib.h>
void push(int n);
void pop();
void peek();
void display();
struct Node{
	struct Node *next;
	int val;
}*top;
int main(){
	while( 1 ){
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
		int num, ch;
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\nenter number : ");
				scanf("%d", &num);
				push(num);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
		}
	}
}
void push(int n){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node*));
	newnode->val = n;
	if( top == NULL ){
		newnode->next = NULL;
	}else{
		newnode->next = top;
	}
	top = newnode;
	printf("\n%d has been pushed", n);
}
void pop(){
	struct Node *temp = top;
	if(temp==NULL){
		printf("stack under flow");
		return;
	}
	printf("\n%d has been popped", temp->val);
	top = top->next;
	free(temp);
}
void peek(){
	if(top==NULL){
		printf("stack under flow");
		return;
	}
	printf("peek element is : %d", top->val);
}
void display(){
	struct Node *cur = top;
	if(cur==NULL){
		printf("stack under flow");
		return;
	}
	while( cur != NULL ){
		printf("[ %d ]\n", cur->val);
		cur = cur->next;
	}
}
