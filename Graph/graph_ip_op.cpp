#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> v[10];
int vis[100];

void dfs(int n){
int t;
stack<int> s;
s.push(n);
while(!s.empty()){
    t=s.top();
      if(vis[t]==0)
        {cout<<t<<" ";
         vis[t]=1;
         }
       s.pop();

    for(int i=0;i<v[t].size();i++)
    	  {  if(vis[v[t][i]]==0)
    	  	    s.push(v[t][i]);
                }        
            }
   cout<<endl;
}
void bfs(int n)
{  int t;
  queue<int> q;

  q.push(n);
   vis[n]=1;
   while(!q.empty()){
         t=q.front();
            
          cout<<t<<" ";
           

          for(int i=0;i<v[t].size();i++)
                 {
                 	 if (vis[v[t][i]]==0)
                 	 	 {q.push(v[t][i]);
                 	 	   vis[v[t][i]]=1;
                 	 	 }
                 }   
             q.pop();

   }

   cout<<endl;

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
    cout<<"Enter 'D' for DFS and 'B' for BFS\n";
     char ch;
     cin>>ch;
switch(ch){
	case 'D':
{      
	 cout<<"Starting Vertex?\n";
	 cin>>ver;
	   dfs(ver);
	   break;
}	
case 'B':
{     
	 cout<<"Starting Vertex?\n";
	 cin>>ver;
	   bfs(ver);
	   break;
 }       
default: 
   cout<<"Wrong!!\n";
}

 
    
	return 0;
}