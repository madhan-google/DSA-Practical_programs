#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("enter the size: ");
    scanf("%d", &n);
    int ar[n];
    for(int i=0; i<n; i++) scanf("%d", &ar[i]);
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++)
            if(ar[j]>ar[j+1]){
                int t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
            }
    }
    printf("Sorted: ");
    for(int i=0; i<n; i++) printf("%d ", ar[i]);
    return 0;
}