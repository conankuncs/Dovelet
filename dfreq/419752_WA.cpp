#include<stdio.h>
#include<math.h>
int n,m;
int dp[100][100]; //i자릿수가 j이고, m이 몇개있는지.
int sum=0;
int main() {
	int i,j,k;
	scanf("%d%d",&n,&m);
	int size=1;
	int logs=0;
	for(;size<n;size*=10,logs++);
	if(size>n) {
		size/=10;
		logs--;
	}
	for(i=1;i<=9;i++) {
		if(i==m) dp[1][i]++;
		if(i > 0) dp[1][i]+=dp[1][i-1];
	}
	dp[1][10]=dp[1][9];
	for(i=2;i<=11;i++) {
		for(j=0;j<=9;j++) {
			if(j==m) dp[i][j]++;
			if(j>1) dp[i][j]+=dp[i][j-1];
			if(j-1==m) {
				dp[i][j]+=pow(10,i-1)-1;
			}
			if(j>0) dp[i][j]+=dp[i-1][10];
		}
		if(10-1==m) dp[i][10]+=pow(10,i-1)-1;
		dp[i][10]+=dp[i][9];
		dp[i][10]+=dp[i-1][10];
	}
	int mm=n;
	for(i=0;i<=logs;i++) {
		sum+=dp[i+1][mm%10];
		mm/=10;
	}
	if((n/size)%10==m) sum+=n%size;
	/*
	bool tr=0;
	while(size > 0) {
		int s=n%size;
		int ss=(n/size)%10;
		if(ss >= m && tr) {
			if(ss == m) sum+=s;
			else sum+=pow(10,logs);
			printf("%d\n",pow(10,logs));
		} else if(!tr && ss==m) sum+=s;
		size/=10;
		tr=1;
		logs--;
	}*/
	printf("%d",sum);
}