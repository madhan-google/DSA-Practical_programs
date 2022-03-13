#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int st[MAX];
int top = -1;
void push(int);
void pop();
void peek();
void display();
int main(){
	while(1){
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
		int ch, num;
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\nenter the number : ");
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
	if( top == MAX-1 ){
		printf("\nstack over flow");
	}else{
		st[++top] = n;
		printf("\n%d has been pushed", n);
	}
}
void pop(){
	if( top == -1 ){
		printf("\nstack under flow");
	}else{
		printf("\n%d has been popped", st[top--]);
	}
}
void peek(){
	if( top == -1 ){
		printf("\nstack under flow");
	}else{
		printf("\npeek element is : %d", st[top]);
	}
}
void display(){
	if( top == -1 ){
		printf("\nstack under flow");
	}else{
		int i;
		for(i=top; i>=0; --i){
			printf("\n[ %d ]", st[i]);
		}
	}
}
