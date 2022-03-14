#include<stdio.h>
#include<stdlib.h>
int main(){
    int n; 
    scanf("%d", &n);
    int ar[n];
    printf("enter the elements: ");
    for(int i=0; i<n; i++) scanf("%d", &ar[i]);
    for(int i=1; i<n; i++){
        int j=i-1; 
        int key = ar[i];
        while(j>=0&&ar[j]>key){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }
    for(int i=0; i<n; i++) printf("%d ", ar[i]);
    return 0;
}