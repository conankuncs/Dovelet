#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,sum;
int arr[6000000];
int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sort(arr+1,arr+1+n);
	printf("%d %.0f",arr[n/2],sum/(double)n);
}