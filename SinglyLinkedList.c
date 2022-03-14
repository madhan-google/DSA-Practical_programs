#include<stdio.h>
#include<stdlib.h>
int size;
struct Node{
    struct Node* next;
    int val;
} *head = NULL;
void insertAtFirst(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->val = val;
    if(head==NULL){
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
    size++;
    return;
}
void insertAtEnd(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->val = val;
    if(head==NULL){
        head = newnode;
        return;
    }
    struct Node* cur = head;
    while(cur->next!=NULL) cur = cur->next;
    cur->next = newnode;
    size++;
}
void insertAtMid(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->val = val;
    if(head==NULL){
        head = newnode;
        return;
    }
    int mid = size/2;
    struct Node* cur = head;
    for(int i=0; i<mid; i++) cur = cur->next;
    newnode->next = cur->next;
    cur->next = newnode; 
    size++;

}
int deleteAtFirst(){
    struct Node* temp = head;
    int res = temp->val;
    head = temp->next;
    temp = NULL;
    free(temp);
    return res;
}
int deleteAtLast(){
    struct Node* cur = head;
    while(cur->next->next!=NULL) cur = cur->next;
    int res = cur->next->val;
    cur->next = NULL;
    free(cur->next);
    return res;
}
void show(){
    struct Node* cur = head;
    while(cur!=NULL){
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
}
int main(){
    size = 0;
    int ch, num;
    while(1){
        printf("\n1.Insert at first 2.Insert at end 3.Insert at middle 4.Delete at first 5.Delete at end 6.Show 7.Exit");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nenter the element: ");
                scanf("%d", &num);
                insertAtFirst(num);
                break;
            case 2:
                scanf("%d", &num);
                insertAtEnd(num);
                break;
            case 3:
                scanf("%d", &num);
                insertAtMid(num);
                break;
            case 4:
                printf("%d deleted succesfully\n", deleteAtFirst());
                break;
            case 5:
                printf("%d deleted succesfully\n", deleteAtLast());
                break;
            case 6:
                show();
                break;
            case 7:
                exit(1);
        }
    }
    return 0;
}