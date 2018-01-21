#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
    {
       int t=*a;
       *a=*b;
       *b=t;
    }
void selection_sort(int a[],int n)
{

int min;
  for(int j=0;j<n;j++)
  	 {
  	    min=j;	 
 for(int i=j;i<n;i++)
          {
       if(a[i]<a[min])
            min=i;
        }
   swap(&a[min],&a[j]);
      }   

} 
int main()
{  int n;
	cin>>n;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];
selection_sort(a,n);
for(int i=0;i<n;i++)
  cout<<a[i]<<" ";

return 0;	
}

