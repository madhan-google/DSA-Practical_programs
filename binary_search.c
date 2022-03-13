#include<stdio.h>
#include<stdlib.h>
void sort(int**, int);
int find(int*, int, int);
int count;
int main(){
    int n;
    scanf("%d", &n);
    int* ar = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", ar+i);
    int target;
    scanf("%d", &target);
    sort(&ar, n);
    count = 0;
    int index = find(ar, target, n);
    if(index==-1){
        printf("not found");
    }else{
        printf("element found in %d index", (index+1));
    }
}
int find(int* ar, int t, int n){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(*(ar+mid)==t){
            return mid;
        }else if(*(ar+mid)<t){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return -1;
}
void sort(int** ar, int n){
    int *arr = *ar;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(*(arr+i)>*(arr+j)){
                int t = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = t;
            }
        }
    }
}