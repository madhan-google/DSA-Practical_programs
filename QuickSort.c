#include<stdio.h>
#include<stdlib.h>
int partition(int ar[], int s, int e){
	int pivot = ar[e];
	int i, pind = s;
	for(i=s; i<e; i++){
		if(ar[i]<=pivot){
			int t = ar[i];
			ar[i] = ar[pind];
			ar[pind] = t;
			pind++;
		}
	}
	int t = ar[e];
	ar[e] = ar[pind];
	ar[pind] = t;
	return pind;
}
void sort(int ar[], int s, int e){
	if(s>=e) return;
	int pind = partition(ar, s, e);
	sort(ar, s, pind-1);
	sort(ar, pind+1, e);
}
int main()
{
	int n;
	scanf("%d", &n);
	int ar[n];
	for(int i=0; i<n; i++) scanf("%d", &ar[i]);
	sort(ar, 0, n);
	printf("\nSorted Array: ");
	for(int i=0; i<n; i++) printf("%d ", ar[i]);
}

















