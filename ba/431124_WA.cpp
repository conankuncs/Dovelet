#include<stdio.h>
#include<deque>
using namespace std;
int d[99999],T[99999],F[99999],N,S,H[99999],D[99999],i,j,Q[99999],h=1,t=1;
int main() {
	scanf("%d%d",&N,&S);
	for(i=1;i<=N;i++) {
		scanf("%d%d",&T[i],&F[i]);
		H[i] = H[i-1]+T[i];
		D[i] = D[i-1]+F[i];
	}
	Q[t++]=N+1;
	for(i=N;i>=1;i--) {
		for(j=h;j<t-1;j++) {
			if((d[Q[j+1]]-d[Q[j]])/(H[Q[j]-1]-H[Q[j+1]-1]) < D[N]-D[i-1]) h++;
			else break;
		}
		d[i] = d[Q[h]]+(S+H[Q[h]-1]-H[i-1])*(D[N]-D[i-1]);
	/*	for(j=t-1;j>h;j--) {
			if((d[i]-d[Q[j]])/(H[Q[j]-1]-H[i-1]) < (d[Q[j]]-d[Q[j-1]])/(H[Q[j-1]-1]-H[Q[j]-1])) t--;
			else break;
		}*/
		Q[t++]=i;
	}
	printf("%d",d[1]);
}