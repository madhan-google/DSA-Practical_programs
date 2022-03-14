#include<stdio.h>  
#include<stdlib.h>
# define max 5 
int queue[max]; 
int front=-1;  
int rear=-1;  
void enqueue(int element){  
    if(front==-1 && rear==-1) {  
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }else if((rear+1)%max==front) printf("\nQueue is overflow");  
    else {  
        rear=(rear+1)%max;       
        queue[rear]=element; 
    }  
}  
  
int dequeue(){  
    if((front==-1) && (rear==-1)) printf("\nQueue is underflow");   
    else if(front==rear){  
        printf("\nThe dequeued element is %d", queue[front]);  
        front=-1;  
        rear=-1;  
    }else{  
        printf("\nThe dequeued element is %d", queue[front]);  
        front=(front+1)%max;  
    }  
}  
void display(){  
    int i=front;  
    if(front==-1 && rear==-1){  
        printf("\n Queue is empty");  
    }else{  
        printf("\nElements in a Queue are :");  
        while(i<=rear)  {  
            printf("%d,", queue[i]);  
            i=(i+1)%max;  
        }  
    }  
}  
int main()  {  
    int ch=1,x; 
      
    while(!0) {  
        printf("\n1.insert 2.delete 3.show 4.exit\nenter your choice: "); 
        scanf("%d", &ch);  
        switch(ch){  
            case 1:  
                printf("enter the element: ");  
                scanf("%d", &x);  
                enqueue(x);  
                break;  
            case 2:  
                dequeue();  
                break;  
            case 3:  
                display();  
                break;
            case 4:
                exit(0);
        }
    }  
    return 0;  
}  