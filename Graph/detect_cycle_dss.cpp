#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
vector<int> v[10];

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



int main(){

    int ve,ver,e,a,b,f=0;
	cout<<"Edges?"<<endl;
	cin>>e;
	cout<<"Vertex?"<<endl;
	cin>>ve;
 
  cout<<"Enter the Edges:\n";

  for(int i=0;i<e;i++)
      {  cin>>a;
         cin>>b;
          v[a].push_back(b);
          v[b].push_back(a);
  
    }
for(int i=0;i<10;i++){

    if(v[i].size()>0)
        makeset(i);
}
for (int i = 0; i < 10; ++i)
{
  for(int j=0;j<v[i].size();j++)
     {
       if(i<v[i][j])
         {
          a=find(i);
          b=find(v[i][j]);
          if(a==b)
            f=1;
          union2(i,v[i][j]);
         }
     }

}

if (f==0)
    cout<<"No cycles:\n";
  else
    cout<<"yes there is cycle\n";

	return 0;   
}