#include <iostream>
#define INF 1000
using namespace std;
int graph[100][100];
int path[100][100];

int main() {
for(int i=0;i<100;i++){
for(int j=0;j<100;j++)
   { if(i!=j)
  	 graph[i][j]=INF;
  	 path[i][j]=1000;
   }}
  int ver,edg,a,b,w;
  cin>>edg>>ver;
  for(int i=0;i<edg;i++)
     {
     	 cin>>a>>b>>w;
     	 graph[a][b]=w;
     	 path[a][b]=a;
     }
   
  for(int k=0;k<ver;k++)
   {
   	 for(int i=0;i<ver;i++)
      {
      	for(int j=0;j<ver;j++)
      	   {
      	   	if(graph[i][j]>(graph[i][k]+graph[k][j]))
      	       { graph[i][j]=graph[i][k]+graph[k][j];
      	         path[i][j]=path[k][j];
      	       }
      	   }
      }
    } 
    

 cout<<"All pair shortest paths:\n";   
for (int i = 0; i < ver; ++i)
{
  for (int j = 0; j < ver; ++j)
  {
    if (i!=j)
       {  int k=j;
         cout<<j<<"<-";
         while(path[i][k]!=i){
            
            k=path[i][k];
            cout<<k<<"<-";
         }
         cout<<i<<endl;
       }
       
      }
      cout<<endl;
}
  
	return 0;
}