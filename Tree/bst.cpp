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
bool search(bst* root,int data)
{
	if (root==NULL)
		return false;
	else if(data==root->data)
  		return true;
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

bst* remove(bst* root,int data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left=remove(root->left,data);
	else if (data>root->data)
		root->right=remove(root->right,data);
     else //found..,,
           {
            //case 1:no child (leaf node)
           
            if (root->left==NULL && root->right==NULL)
            	 {free(root);
            	  root=NULL;
            	   return root;

                   }
             //case 2:One child
             
             else if(root->left==NULL)
             {
             	bst *temp=root;
             	root=root->right;
             	free(temp);
             }      
             else if(root->right==NULL)
             {
             	bst *temp=root;
             	root=root->left;
             	free(temp);
             }
             //case 3 :two child 
             else {
             	//either find maximum element in left subtree or minimum element in right subtree
             	//replace it by the root element which has to be deleted 
             	bst *temp=min(root->right);  
             	root->data=temp->data;
             	//remove the duplicate copy left of that max or min element
             	root->right=remove(root->right,temp->data);  
             }
           }
      return root;     
}

int height(bst* root)                   //for height of binary search tree
{
	if(root==NULL)
		return -1;
	else 
		return max(height(root->left),height(root->right))+1;
}
void display(bst* root)        //pre-order traversal
{
	if (root==NULL)
		return;
	cout<<root->data<<endl;
	display(root->left);
	display(root->right);
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
cout<<"Height of tree:"<<height(root);
cout<<endl;
root=remove(root,45);
cout<<"Height of tree:"<<height(root)<<endl;

int num;
cin>>num;
bool ans=search(root,num);
if(ans==true)
	cout<<"Found\n";
else
	cout<<"Not Found\n";
display(root);
level_order(root);

}
