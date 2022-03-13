#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int rear = 0, front = 0;
int ar[MAX];
void enqueue(int val){
    if(rear==MAX){
        printf("queue over flow");
        return;
    }
    ar[rear++] = val;
}
int dequeue(){
    if(front==rear){
        printf("queue under flow");
        return -1;
    }
    return ar[front++];
}
void show(){
    if(front==rear){
        printf("queue under flow");
        return ;
    }
    for(int i=front; i<rear; i++) printf("%d ", ar[i]);
}
int main(){
    int num, ch;
    while(!0){
        printf("\n1.enqueue\n2.dequeue\n3.show\n4.exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                printf("\n%d has been deleted",dequeue());
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
        }
    }
}