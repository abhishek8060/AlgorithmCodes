#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> v[10];
int vis[100];

void dfs(int n){
int t,f=0;
stack<int> s;
s.push(n);
while(!s.empty()){
    t=s.top();
      if(vis[t]==0)
        {
         vis[t]=1;
         }
        else
          f++; 
       s.pop();

    for(int i=0;i<v[t].size();i++)
    	  {  if(vis[v[t][i]]==0)
    	  	    s.push(v[t][i]);
                }        
            }
   cout<<endl;

   cout<<"There are "<<f<<" cycle(s) in this graph\n";
}



int main(){

    int ve,ver,e,a,b;
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
    cout<<"Enter starting vertex:\n";
    cin>>ver;

    dfs(ver);
 
    
	return 0;
}