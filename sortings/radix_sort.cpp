#include <bits/stdc++.h>
using namespace std;

int max(int a[],int n)
{
 int mx=a[0];
 for (int i = 0; i < n; ++i)

 {
  if (mx<a[i]);
    mx=a[i];
 }
 return mx;
}      
void radix_sort(int a[],int n,int div)
{  
         vector<int> store[10];
  int j=0;
 for (int i = 0; i < n; i++)
  store[(a[i]/div)%10].push_back(a[i]);

int l=0;
for (int i = 0; i <10; i++)
{
  for(int k=0;k<store[i].size();k++)
     a[l++]=store[i][k];
}
 
}






 

int main()
{ 
  int n;
	cin>>n;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];

int m=max(a,n);
int d=1;
while(m>0)

 {
  radix_sort(a,n,d);
  d*=10;
  m/=10;
 }
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
return 0;	
}

