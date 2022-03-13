#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
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
struct Node{
	int val;
	struct Node *next;
};
VD push(struct Node **head, int val){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->val = val;
	newnode->next = (*head);
	(*head) = newnode;
}
VD append(struct Node **head, int val){
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->val = val;
	newnode->next = NULL;
	if(*head==NULL){
		*head = newnode;
		return;
	}
	struct Node *cur = *head;
	WHL(cur->next!=NULL){
		cur = cur->next;
	}
	cur->next = newnode;
	
}
VD delFirst(struct Node **head){
	if(head==NULL) return;
	struct Node *temp = *head;
	*head = temp->next;
	free(temp);
}
VD delLast(struct node **head){
	if(head==NULL) return;
	struct Node *temp = *head;
	if(temp->next==NULL){
		temp = NULL;
		free(temp);
		return;
	}
	WHL(temp->next->next!=NULL){
		temp = temp->next;
	}
	temp->next = NULL;
	free(temp->next);
}
VD reverseList(struct Node *head){
	
}
VD print(struct Node **head){
	struct Node *cur = *head;
	WHL(cur!=NULL){
		pf("[%d]->", cur->val);
		cur = cur->next;
	}
}
int main()
{
	struct Node *head = NULL;
	INF{
		$ n, ch;
		pfs("\n1.append\n2.push\n3.delFirst\n4.display\n5.delLast\n6.exit\n")
		sfn(ch)
		switch(ch){
			case 1:
				sfn(n)
				append(&head, n);
				break;
			case 2:
				sfn(n)
				push(&head, n);
				break;
			case 3:
				delFirst(&head);
				break;
			case 4:
				print(&head);
				break;
			case 5:
				delLast(&head);
				break;
			case 6:
				exit(0);
		}
	}
	print(&head);
}

















