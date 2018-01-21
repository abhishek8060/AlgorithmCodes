#include <bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> ipair;


class Graph{
 public:
  int ver,edg;
  vector<ipair > edges[1000];
   
  Graph(int ver ,int edg) //constructor
   {
     this->ver=ver;
     this->edg=edg;
   }

   void addEdge(int a,int b,int w)
    { edges[a].push_back(make_pair(b,w));
      edges[b].push_back(make_pair(a,w)); }
  
  void dijkstra(int src);

}; 

void Graph::dijkstra(int src){

 priority_queue <ipair ,vector<ipair > ,greater<ipair > > pq;

 vector<int> dis(ver+1,INF);
 vector<int> parent(ver+1,-1);

 pq.push(make_pair(0,src));
 dis[src]=0;
 parent[src]=0;

 while(!pq.empty()){

  int u= pq.top().second;
  pq.pop();

  for (int i = 0; i < edges[u].size(); ++i)
  {
    int v=edges[u][i].first;
    int w=edges[u][i].second;

    if (dis[v] > (dis[u]+w))
    {
      dis[v]=dis[u]+w;
      parent[v]=u;
      pq.push(make_pair(dis[v],v));
    }
  }
 } 
 cout<<"Vertices with minimum edge weight from source\n";
 for (int i = 0; i <ver; ++i)
   cout<<i<<" "<<dis[i]<<endl;
 cout<<"All shortest paths to source\n";
 int k;
 for (int i =1; i < ver; ++i)
 {  k=i;
   while(1){
         
        cout<<k<<"-";
         if(parent[k]==src)
           {cout<<parent[k];
            break;}
         else
           k=parent[k];
          }  
       cout<<endl;
     }
}

int main(){

  
  int ve,a,e,b,w,src;
  cout<<"Vertex?"<<endl;
  cin>>ve;
  cout<<"Edges?"<<endl;
  cin>>e;
    Graph g(ve,e);  
 
  cout<<"Enter the Edges (starting with '0') with weight:\n";

  for(int i=0;i<e;i++)
      {  cin>>a>>b>>w;
         g.addEdge(a,b,w);
       }
 
   cout<<"Enter the source\n";
   cin>>src;
    g.dijkstra(src);
       

  return 0;

}