#include <bits/stdc++.h>
using namespace std;

int p[1100];
int ran[1100];

int makeset(int n)
 {
   for(int i=0;i<n;i++)
      p[i]=i;
 }

int find(int i)

{
  return (p[i]==i)?i:(p[i]=find(p[i]));
} 

bool issame(int i, int j)
{
  return find(i)==find(j);

}

void union2(int i,int j){
  if(!issame(i,j)){

    int x=find(i),y=find(j);
    if (ran[x]>ran[y])
         p[y]=x;
     else
     {
      p[x]=y;
      if(ran[x]==ran[y])
        ran[y]++;
     }  

  }
}
int main()
{
	
makeset(7);

union2(0,1);
union2(1,2);
union2(2,3);
union2(5,6);

cout<<find(2)<<endl;;
	return 0;
}