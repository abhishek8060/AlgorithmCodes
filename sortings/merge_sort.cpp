#include <bits/stdc++.h>
using namespace std;
void merge1(int* ,int ,int);


void merge_sort(int a[],int n)
{
   if(n>1)
       {

        int lsize=n/2;
          int rsize=n-lsize;
        merge_sort(a,lsize);
        merge_sort(a,rsize);
        merge1(a,lsize,rsize);
      }

} 

void merge1(int a[],int lsize,int rsize)
  { 
     int i,j,k=0;
     int left[lsize],right[rsize];
      
      for (i = 0; i <lsize; ++i)
        left[i]=a[k++];
      for (i = 0; i < rsize; ++i)
        right[i]=a[k++];

    i=0;
    j=0;
     k=0;
    while(i<lsize && j< rsize)
          {
               if(left[i]<=right[j])
                    a[k++]=left[i++];
                  else
                    a[k++]=right[j++];

          }
    while(i<lsize)
         a[k++]=left[i++];  //for remaining elements
    while(j<rsize)
         a[k++]=right[j++];       
 }         






int main()
{  

  int n;
	cin>>n;
int a[n];

for(int i=0;i<n;i++)
	cin>>a[i];

merge_sort(a,n);

for(int i=0;i<n;i++)
  cout<<a[i]<<" ";

return 0;	
}

