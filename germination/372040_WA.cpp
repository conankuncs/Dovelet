#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct A {
	int s,e;
	int ind;
	bool operator<(const A &a) const {
		return e < a.e;
	}
};
struct B {
	int value;
	int ind;
};
bool cmp(B a,B b) {
	return a.value > b.value;
}
A flowers[5];
B plants[5];
int vis[5];
string s[5];
string arr[5]={"Poppy","Carnation","Sunflower","Daisy","Pansy"};
int main() {
	int i,j;
	for(i=0;i<5;i++) {
		cin>>flowers[i].s>>flowers[i].e;
		flowers[i].ind = i;
	}
	for(i=0;i<5;i++) {
		cin>>plants[i].value;
		plants[i].ind = i;
	}
	sort(flowers,flowers+5);
	sort(plants,plants+5,cmp);
	bool t=true;
	for(i=0;i<5;i++) {
		int cnt=0;
		for(j=4;j>=0;j--) {
			if(vis[j] == 0 && flowers[j].s <= plants[i].value && flowers[j].e >= plants[i].value) {
				vis[j]+=1;
				s[plants[i].ind]=arr[flowers[j].ind];
				cnt++;
			}
		}
		if(cnt > 1) {
			t=false;
			break;
		}
	}
	/*for(i=0;i<5;i++) {
		if(vis[i] != 1 && t) {
			t=false;
			break;
		}
	}*/
	if(!t) cout<<"Ambiguous";
	else {
		for(i=0;i<5;i++) cout<<s[i]<<" ";
	}
}