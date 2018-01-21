#include <bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
//white=0,grey=-1,black=1
typedef pair<int,int> ipair;


class Graph{
 public:
  int ver,edg;
  vector<int> edges[1000];
   bool dfs(int v,int colour[]);
  Graph(int ver ,int edg) //constructor
   {
     this->ver=ver;
     this->edg=edg;
   }

   void addEdge(int a,int b)
    { edges[a].push_back(b);
       }
  
  bool cycle();

};
bool Graph::dfs(int v,int colour[]){

  colour[v]=-1;
  for (int i = 0; i < edges[v].size(); ++i)
  {
     int u=edges[v][i];

     if(colour[u]==-1)
      return true;
    if(colour[u]==0 && dfs(u,colour))
      return true;
  }
 colour[v]=1;
 return false;

}

bool Graph::cycle(){
  int colour[ver];

 memset(colour,0,ver);
  for (int i = 0; i < ver; ++i)
  {  cout<<colour[i]<<endl;
    if(colour[i]==0)
      if(dfs(i,colour)==true)
        return true;
  }

return false; 

}




int main(){

  
  int ve,a,e,b,w,src;
  cout<<"Vertex?"<<endl;
  cin>>ve;
  cout<<"Edges?"<<endl;
  cin>>e;
    Graph g(ve,e);  
 
  cout<<"Enter the Edges (starting with '0') :\n";

  for(int i=0;i<e;i++)
      {  cin>>a>>b;
         g.addEdge(a,b);
       }
 
   
    if(g.cycle())
       cout<<"Contains cycle:\n";
     else
        cout<<"Does not contain cycle\n";
       

  return 0;

}