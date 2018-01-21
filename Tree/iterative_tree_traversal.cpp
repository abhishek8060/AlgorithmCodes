#include<bits/stdc++.h>
using namespace std;
struct btree{
	int data;
	btree *left;
	btree *right;
};


btree* newnode(int data){
	btree* node=new btree();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
queue<btree*> q;
btree* insert(btree* root,int data)
{
	
    
    btree *temp = newnode(data);
 
   
    if (root==NULL)
        root = temp;
           
  
    else
    {
        
        btree* current=q.front();
 
        
        if (!current->left)
            current->left = temp;
 
        
        else if (!current->right)
            current->right = temp;
 
       
        if (current->left!=NULL && current->right!=NULL)
            q.pop();
    }
 

    q.push(temp);
   return root;
}
 
void pre_iterative(btree* root)
{

btree *temp=root;
if (temp==NULL)
{
	cout<<"Tree is empty\n";
	return;
}


stack<btree*> s;
s.push(temp);
while(!s.empty())
{    temp=s.top();
	s.pop();
	cout<<temp->data<<" ";
	if (temp->right!=NULL)
         s.push(temp->right);
     if (temp->left!=NULL)
         s.push(temp->left);
     
}
cout<<endl;
}



void inorder_iterative(btree* root)
{
btree* ptr=root;
if (root==NULL)
{
	cout<<"Tree is empty\n";
	return;
}

stack<btree*> s;

while(1)
{
	while(ptr->left!=NULL)
	{
		s.push(ptr);
		ptr=ptr->left;
	}
	while(ptr->right==NULL)
	{
		cout<<ptr->data<<" ";
		if(s.empty())
			{    
				cout<<endl;
				return;
			}
		ptr=s.top();
		s.pop();
	}
  cout<<ptr->data<<" ";
  ptr=ptr->right;
 }
 cout<<endl;
}


void post_iterative(btree* root)
{
	
	if(root==NULL)
	 {
	 	 cout<<"Tree is empty\n";
	     return;
	 }
	 
stack<btree*> s1;
stack<btree*> s2;
s1.push(root);	 
while(!s1.empty())
{    root=s1.top();
	s1.pop();
	if (root->left!=NULL)
	{
		s1.push(root->left);
	}
	if (root->right!=NULL)
	{
		s1.push(root->right);
	}
 	s2.push(root);
}
while(!s2.empty())
{     btree* temp=s2.top();
	cout<<temp->data<<" ";
	s2.pop();
}
cout<<endl;
}	 
void level_order(btree* root)
{
	if (root==NULL)
		return;
	queue<btree*> q;
	q.push(root);
	
	while(!q.empty()){
		btree* current=q.front();
			cout<<current->data<<" "; 
			if (current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
			q.pop();
	}
	cout<<endl;
}

int main()
{  btree* root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,7);
    
    pre_iterative(root);
    inorder_iterative(root);
	post_iterative(root);
	level_order(root);
	return 0;
}