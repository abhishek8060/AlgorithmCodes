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
bst* search(bst* root,int data)
{
	if (root==NULL)
		return NULL;
	else if(data==root->data)
  		return root;
    else if(data<root->data)
    	return search(root->left,data);
    else
    	return search(root->right,data);
}
bst* min(bst* root)
{     
     
	while(root->left!=NULL)
		 root=root->left;
		return root;
}


void level_order(bst* root)
{
	if (root==NULL)
		return;
	queue<bst*> q;
	q.push(root);
	//while there is one discovered node
	while(!q.empty()){
		bst* current=q.front();
			cout<<current->data<<" "; 
			if (current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
			q.pop();
	}
cout<<endl;
}

bst* getsuccessor(bst* root,int data)
{
	bst* current=search(root,data);
	if (current==NULL)
	{
		cout<<"data not found\n";
		return NULL;
	}
	//if current has right subtree
	if (current->right!=NULL){
            return min(current->right);
	}
	else  //if it has no right subtree
	{
		bst* ancestor=root;
		bst* successor=NULL;
		while(ancestor!=current)
		{
			if (current->data<ancestor->data)
			{
				successor=ancestor;
				ancestor=ancestor->left;

			}
			else
				ancestor=ancestor->right;
		}
		return successor;
		}
	}



int main(){

bst* root=NULL;
root=insert(root,4);
root=insert(root,2);
root=insert(root,6);
root=insert(root,1);
root=insert(root,3);
root=insert(root,5);
root=insert(root,7);
root=insert(root,8);

cout<<"TREE Is:\n";
level_order(root);

cout<<"Enter the value to find its inorder successor\n";
int num;
cin>>num;
cout<<"Successor is:"<<getsuccessor(root,num)->data;
cout<<endl; 

}
