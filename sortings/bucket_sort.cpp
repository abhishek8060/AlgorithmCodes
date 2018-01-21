#include <bits/stdc++.h>

using namespace std;
int bket[100000];


void bucket_sort(int a[],int n)
{
    


    for(int i=0;i<n;i++)
      { int index=a[i];
        bket[index]++;
    }
    
    

     int k=0;
     for(int i=0;i<100000;i++)
         {     if(bket[i]>0)
                   {
            for(int j=0;j<bket[i];j++)
                       a[k++]=i;}
          }




} 
int main()
{  int n;
	cin>>n;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];

bucket_sort(a,n);

for (int i = 0; i <n; ++i)
{
  cout<<a[i]<<" ";
}

return 0;	
}

