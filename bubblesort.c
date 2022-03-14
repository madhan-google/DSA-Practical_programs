#include<stdio.h>
int main(){
	int n;
	printf("enter the size : ");
	scanf("%d", &n);
	printf("\nenter the elements : ");
	int ar[n], i, j;
	for(i=0; i<n; i++) scanf("%d", &ar[i]);
	for(i=0; i<n; i++){
		int min_ind = i;
		for(j=i+1; j<n; j++)
			if(ar[min_ind]>ar[j]) min_ind = j;
		int t = ar[i];
		ar[i] = ar[min_ind];
		ar[min_ind] = t;
	}
	printf("\nsorted :\n");
	for(j=0; j<n; j++) printf("%d ", ar[j]);
	return 0;
}
