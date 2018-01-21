#include<bits/stdc++.h>
using namespace std;

bool RED=true;
bool BLACK=false;

struct rbt{
	int data;
	rbt *left;
	rbt *right;
	bool color;
};

bool isRed(rbt* x)
{
	if(x==NULL)
		return false;
	return (x->color==RED);
}

rbt* GetNewNode(int data){
	rbt *node=new rbt();
	node->data=data;
	node->left=node->right=NULL;
    node->color=RED;
	return node;

}



rbt* rightRotate(rbt *y)
{
	rbt* x=y->left;
	rbt* tmp=x->right;

   
	x->right=y;
	y->left=tmp;

    x->color=y->color;
    y->color=RED;
   

    return x;

}

rbt* leftRotate(rbt* z)
{

	rbt *y=z->right;
	rbt *tmp=y->left;

	y->left=z;
	z->right=tmp;
    
    y->color=z->color;
	z->color=RED;


	
    return y;
}

void flipcolors(rbt* root)
{
	root->color=RED;
	root->left->color=BLACK;
	root->right->color=BLACK;
}

rbt* insert(rbt* root,int data)
{
   if(root==NULL)
   {
		root=GetNewNode(data);
	
   }

   else if(data<=root->data)
   {
   	root->left=insert(root->left,data);
   }
   else
   {
   	root->right=insert(root->right,data);
   }

   if(isRed(root->right) && !isRed(root->left))
  	            root=leftRotate(root);
   if(isRed(root->left) && isRed(root->left->left))
                 root=rightRotate(root);
   if(isRed(root->right) && isRed(root->left))
                flipcolors(root);              	        

   return root;
}
bool search(rbt* root,int data)
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
rbt* min(rbt* root)
{     
     
	while(root->left!=NULL)
		 root=root->left;
		return root;
}

rbt* remove(rbt* root,int data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left=remove(root->left,data);
	else if (data>root->data)
		root->right=remove(root->right,data);
     else 
           {
           
           
            if (root->left==NULL && root->right==NULL)
            	 {free(root);
            	  root=NULL;
            	   return root;

                   }
             
             
             else if(root->left==NULL)
             {
             	rbt *temp=root;
             	root=root->right;
             	free(temp);
             }      
             else if(root->right==NULL)
             {
                rbt *temp=root;
             	root=root->left;
             	free(temp);
             }
             
             else {
             	
             	rbt *temp=min(root->right);  
             	root->data=temp->data;
             	
             	root->right=remove(root->right,temp->data);  
             }
           }

   if(isRed(root->right) && !isRed(root->left))
  	            root=leftRotate(root);
   if(isRed(root->left) && isRed(root->left->left))
                 root=rightRotate(root);
   if(isRed(root->right) && isRed(root->left))
                flipcolors(root);           
      return root;     
}

void level_order(rbt* root)
{
	if (root==NULL)
		return;
	queue<rbt*> q;
	q.push(root);
	
	while(!q.empty()){
		rbt* current=q.front();
			cout<<current->data<<" "; 
			if (current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
			q.pop();
	}
}
void display(rbt* root)        
{
	if (root==NULL)
		return;
	cout<<root->data<<" ";
	display(root->left);
	display(root->right);
}


int main(){

rbt* root=NULL;
root=insert(root,1);
root->color=BLACK;
root=insert(root,2);
root=insert(root,3);
root=insert(root,4);
root=insert(root,5);
root=insert(root,6);
root=insert(root,7);
root=insert(root,8);


int num;
cout<<"Enter the number to search:\n";
cin>>num;
bool ans=search(root,num);
if(ans==true)
	cout<<"Found\n";
else
	cout<<"Not Found\n";
cout<<"Pre-order traversal:\n";
display(root);
cout<<endl;
cout<<"Level-order traversal:\n";
level_order(root);
cout<<endl;

root=remove(root,4);
cout<<"Pre-order traversal:After removing 4\n";
display(root);
cout<<endl;
cout<<"Level-order traversal:\n";
level_order(root);
cout<<endl;



}
