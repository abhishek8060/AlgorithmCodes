#include <bits/stdc++.h>
using namespace std;


void insertion_sort(int a[],int n)
{int key;
    for(int i=1;i<n;i++)
     {
       j=i-1;
        key=a[i];
         while((j>=0) && (key<a[j]))
            {
                a[j]=a[j+1];
                j--;
            }
          a[j+1];  
     
      }   

} 
int main()
{  int n;
	cin>>n;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];


insertion_sort(a,n);
for(int i=0;i<n;i++)
  cout<<a[i]<<" ";

return 0;	
}

