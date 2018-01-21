#include<bits/stdc++.h>
using namespace std;

struct bst{
	int data;
	bst *left;
	bst *right;
};

bst* GetNewNode(int data){
	bst *node=new bst();
	node->data=data;
	node->left=node->right=NULL;
	return node;

}

bst* insert(bst* root,int data)
{
	if(root==NULL)
	{
		root=GetNewNode(data);
    }

   else if(data<=root->data)
   {
   	root->left=insert(root->left,data);
   }
   else{
   	root->right=insert(root->right,data);
   }
   return root;
}




void pre(bst* root)       
 
{
	if (root==NULL)
		return;
	cout<<root->data<<endl;
	pre(root->left);
	pre(root->right);
}

void in(bst* root)        

{
	if (root==NULL)
		return;
	in(root->left);
	cout<<root->data<<endl;
	in(root->right);
}

void post(bst* root)       
 
{
	if (root==NULL)
		return;
	post(root->left);
	post(root->right);
	cout<<root->data<<endl;
}

void level(bst* root)  

{
	if (root==NULL)
		return;
	queue<bst*> q;
	q.push(root);
	
	while(!q.empty()){
		bst* current=q.front();
			cout<<current->data<<" "; 
			if (current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
			q.pop();
	}
}
int main(){

bst* root=NULL;
root=insert(root,45);
root=insert(root,35);
root=insert(root,90);
root=insert(root,1);
root=insert(root,50);
root=insert(root,40);
root=insert(root,30);
root=insert(root,100);
cout<<"Enter choice:\n";
cout<<"1.Pre-Order Traversal\n";
cout<<"2.In-Order Traversal\n";
cout<<"3.Post-Order Traversal\n";
cout<<"4.Level-Order Traversal\n";
int ch;
cin>>ch;
switch(ch){
	case 1:
	     pre(root);
	     break;
	case 2:
	     in(root);
	     break;
	case 3:
	     post(root);
	     break;
	case 4:
	     level(root);
	     break;
	default:
	 cout<<"Wrong choice!!\n";



}

}

