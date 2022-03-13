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
VD sort(int ar[], int s, int e){
	if(s>=e) return;
//	int mid = (s+e)/2;
	int pind = partition(ar, s, e);
	sort(ar, s, pind-1);
	sort(ar, pind+1, e);
}
int main()
{
	$ n;
	sfn(n)
	$ ar[n], i, j;
	FOR(i, 0, n, 1) sfn(ar[i])
	sort(ar, 0, n-1);
	FOR(i, 0, n, 1){
		pfn(ar[i]) _
	}
}

















