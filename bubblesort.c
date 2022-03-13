#include<stdio.h>
int main(){
	int n;
	printf("enter the size : ");
	scanf("%d", &n);
	printf("\nenter the elements : ");
	int ar[n], i, j;
	for(i=0; i<n; i++) ar[i] = 0;
	for(i=0; i<n; i++){
		scanf("%d", &ar[i]);
	}
	int count = 0;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(ar[i]>ar[j]){
				int t = ar[i];
				ar[i] = ar[j];
				ar[j] = t;
				count++;
			}
		}
	}
	printf("\nsorted :\n");
	for(j=0; j<n; j++){
		printf("%d ", ar[j]);
	}
	printf("\ncount - %d", count);
	return 0;
}
