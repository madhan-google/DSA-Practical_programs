#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int pow;
    struct Node *next;
};
void create(int coeff, int pow, struct Node** head){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;
    if(*head==NULL){
        *head = newnode;
        return;
    }
    struct Node* cur = *head;
    while(cur->next!=NULL){
        cur = cur->next;
    }
    cur->next = (struct Node*)malloc(sizeof(struct Node));
    cur->next = newnode;
}
struct Node* add(struct Node* temp1, struct Node* temp2){
    struct Node* out = NULL;
    while(temp1&&temp2){
        if(temp1->pow>temp2->pow){
            create(temp1->coeff, temp1->pow, &out);
            temp1 = temp1->next;
        }else if(temp1->pow<temp2->pow){
            create(temp2->coeff, temp2->pow, &out);
            temp2 = temp2->next;
        }else{
            create(temp1->coeff+temp2->coeff, temp1->pow, &out);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1||temp2){
        if(temp1){
            create(temp1->coeff, temp1->pow, &out);
            temp1 = temp1->next;
        }
        if(temp2){
            create(temp2->coeff, temp2->pow, &out);
            temp2 = temp2->next;
        }
    }
    return out;
}
struct Node* sub(struct Node* p1, struct Node* p2){
    struct Node* res = NULL;
    while(p1&&p2){
        if(p1->pow>p2->pow){
            create(p1->coeff, p1->pow, &res);
            p1 = p1->next;
        }else if(p1->pow<p2->pow){
            create(p2->coeff, p2->pow, &res);
            p2 = p2->next;
        }else{
            create(p1->coeff-p2->coeff, p2->pow, &res);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1||p2){
        if(p1){
            create(p1->coeff, p1->pow, &res);
            p1 = p1->next;
        }
        if(p2){
            create(p2->coeff, p2->pow, &res);
            p2 = p2->next;
        }
    }
    return res;
}
void print(struct Node* head){
    struct Node* cur = head;
    while(cur!=NULL){
        printf(" %dx^%d +", cur->coeff, cur->pow);
        cur = cur->next;
    }
}
int main(){
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *res = NULL;
    create(2, 5, &poly1);
    create(5, 4, &poly1);
    create(6, 3, &poly1);
    create(8, 2, &poly1);
    create(12, 1, &poly1);
    create(34, 0, &poly1);

    create(2, 4, &poly2);
    create(7, 3, &poly2);
    create(7, 2, &poly2);
    create(3, 1, &poly2);
    printf("\n");
    print(poly1);
    printf("\n");
    print(poly2);
    printf("\n----------------------------------------\n");
    res = add(poly1, poly2);
    print(res);
    printf("\n\n");
    print(poly1);
    printf("\n");
    print(poly2);
    printf("\n---------------------------------------\n");
    res = sub(poly1, poly2);
    print(res);
    return 0;
}