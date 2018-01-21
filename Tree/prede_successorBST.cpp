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

void getpre_suc(bst* root,bst*& pre,bst*& suc,int data)
{
	if (root==NULL)
		return;
if (root->data==data)
 {
	
	if (root->left!=NULL)
	{
		bst *tmp=root->left;
		while(tmp->right)
		{
			tmp=tmp->right;
		}
		pre=tmp;
	}
	if (root->right!=NULL)
	{
		bst *tmp=root->right;
		while(tmp->left)
			tmp=tmp->left;
		suc=tmp;

	}
	return;

 }

 if(data<root->data){
 	suc=root;
 	getpre_suc(root->left,pre,suc,data);
 }
 else
 {
 	pre=root;
 	getpre_suc(root->right,pre,suc,data);
 }
}



int main(){

bst* root=NULL;
bst *pre=NULL;
bst *suc=NULL;
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

cout<<"Enter the value to find its inorder successor & predecessor\n";
int num;
cin>>num;
getpre_suc(root,pre,suc,num);
cout<<"successor is:"<<suc->data<<endl;
cout<<"predecessor is:"<<pre->data<<endl;

}
