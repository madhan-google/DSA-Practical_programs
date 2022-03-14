#include<stdio.h>
#include<stdlib.h>
int search(int*, int, int, int);
int main(){
    int n;
    scanf("%d", &n);
    int* ar = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", ar+i);
    int target;
    scanf("%d", &target);
    int index = search(ar, target, 0, n);
    if(index==-1) printf("not found");
    else printf("element found in %d index", (index+1));
}
int search(int* ar, int t, int s, int e){
    if(s<e){
        int mid = (s+e)/2;
        if(*(ar+mid)==t) return mid;
        else if(*(ar+mid)<t) return search(ar, t, mid+1, e);
        else return search(ar, t, s, mid-1);
    }
    return -1;
}
