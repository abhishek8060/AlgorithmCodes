#include<bits/stdc++.h>
#define INF 100000
using namespace std;
int a[10000];
int tree[100000];

void buildSegTree(int ss,int se,int index){

	if(ss==se){
		tree[index]=a[ss];
		return;}
	int mid=(ss+se)/2;
	buildSegTree(ss,mid,2*index+1);
	buildSegTree(mid+1,se,2*index+2);
	tree[index]=min(tree[2*index+1],tree[2*index+2]);
}

void rangeQuery(int ss,int se,int qs,int qe,int i){
	if(qs>se || qe<ss)
		return INF;
	if(qs<=ss && qe>=se)return tree[i];

	int mid=(ss+se)/2;
	return max(rangeQuery(ss,mid,qs,qe,2*i+1),rangeQuery(mid+1,se,qs,qe,2*i+2));
}

int main(){
cout<<"enter size of array:\n";
int n;
cin>>n;
for (int i = 0; i < n; ++i)
{
	cin>>a[i];
}

buildSegTree(0,n-1,0);
int a,b;
while(1){
cin>>a>>b;
cout<<rangeQuery(1,3)<<endl;
}
	return 0;
}