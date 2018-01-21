#include <bits/stdc++.h>
using namespace std;
int parting(int*,int,int);
void quick_sort(int a[],int start,int end)
{
 if (start<end)
 {
  int pindex=parting(a,start,end);
 
   quick_sort(a,start,pindex-1);

   quick_sort(a,pindex+1,end);

 }
}
int  parting(int a[],int start,int end)
{

    int pivot;
    pivot=a[end];
    int pindex=0;
    for(int i=0;i<end;i++)
          {
             if (a[i]<pivot)
             {
                 swap(a[i],a[pindex]);
                 pindex++;
               }
          }
         
    swap(a[pindex],a[end]);

    return pindex;
        

} 
int main()
{  int n;
	cin>>n;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];
quick_sort(a,0,n-1);
for(int i=0;i<n;i++)
  cout<<a[i]<<" ";

return 0;	
}

