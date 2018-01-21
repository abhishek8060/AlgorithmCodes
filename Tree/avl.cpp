#include <bits/stdc++.h>
using namespace std;

struct avl{
  
  int data;
  int height;
  avl* left;
  avl* right;

};
int height(avl* root)                   
                     //for height of binary search tree
{
	if(root==NULL)
		return 0;
	else 
		return max(height(root->left),height(root->right))+1;
}
int balance(avl* node)
{
	if (node==NULL)
		return 0;
	else
		return height(node->left)-height(node->right);
}
avl* getnode(int data)
{
	avl* tmp=new avl();
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->height=1;
    return tmp;
}

avl* rightRotate(avl *y)
{
	avl* x=y->left;
	avl* tmp=x->right;

   //rotation
	x->right=y;
	y->left=tmp;


    y->height = height(y);
    x->height = height(x);

    return x;

}

avl* leftRotate(avl* z)
{

	avl *y=z->right;
	avl* tmp=y->left;

	y->left=z;
	z->right=tmp;

	z->height = height(z);
    y->height = height(y);

    return y;
}




bool search(avl* root,int data)
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
avl *insert(avl* root,int data)
{

   if (root==NULL)
   	  {root=getnode(data);
       return root;
   	  }
   	else if(data<=root->data)                     
   	                                            //NORMAL BST INSERTION
   		root->left=insert(root->left,data);
   	else
   		root->right=insert(root->right,data);
     

   	root->height=height(root);            
   	                                           //updating height

 

int bal=balance(root);

if (bal>1 && data<root->left->data)         
                                               //LL case
    return rightRotate(root);
if( bal<-1 && data>root->right->data)       
                                               //RR case
	return leftRotate(root); 

if (bal>1 && data>root->left->data)        
                                                //LR case
	{root->left=leftRotate(root->left);
      return rightRotate(root);}
if (bal<-1 && data<root->right->data)       
                                                 //RL case
	{root->right=rightRotate(root->right);
     return leftRotate(root);}

     return root;
}

avl* min(avl* root)
{     
     
	while(root->left!=NULL)
		 root=root->left;
		return root;
}
avl* remove(avl* root,int data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left=remove(root->left,data);
	else if (data>root->data)
		root->right=remove(root->right,data);
     else 
           //found..,,
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
             	avl *temp=root;
             	root=root->right;
             	free(temp);
             }      
             else if(root->right==NULL)
             {
             	avl *temp=root;
             	root=root->left;
             	free(temp);
             }
             //case 3 :two child 
             else {
             	//either find maximum element in left subtree or minimum element in right subtree
             	//replace it by the root element which has to be deleted 
             	avl *temp=min(root->right);  
             	root->data=temp->data;
             	//remove the duplicate copy left of that max or min element
             	root->right=remove(root->right,temp->data);  
             }
           }
      

      if (root==NULL)            
                            //for last element of tree
       	return root;


   	root->height=height(root);            
   	                            //updating height

 

int bal=balance(root);

if (bal>1 && balance(root->left)>=0)         
                                            //LL case
    return rightRotate(root);
if( bal<-1 && balance(root->right)<=0)      
                                            //RR case
	return leftRotate(root);

if (bal>1 && balance(root->left)<0)        
                                             //LR case
	{root->left=leftRotate(root->left);
      return rightRotate(root);}
if (bal<-1 && balance(root->right)>0)       
                                              //RL case
	{root->right=rightRotate(root->right);
     return leftRotate(root);}

     return root;    
}

void display(avl* root)       
                                             //pre-order traversal
{
	if (root==NULL)
		return;
	cout<<root->data<<endl;
	display(root->left);
	display(root->right);
}
int main()
{
avl* root=NULL;
root=insert(root,10);
root=insert(root,20);
root=insert(root,30);
root=insert(root,40);
root=insert(root,50);
root=insert(root,60);
root=insert(root,70);

cout<<"pre-order traversal:\n";
display(root);

root=remove(root,50);
root=remove(root,60);
root=remove(root,70);

cout<<"pre-order traversal:after deletion of 50,60 and 70\n";
display(root);

root=insert(root,55);
root=insert(root,45);

cout<<"pre-order traversal:after insertion of 55 and 45\n";
display(root);

int num;
cout<<"Enter the number to search:\n";
cin>>num;
bool ans=search(root,num);
if(ans==true)
	cout<<"Found\n";
else
	cout<<"Not Found\n";
	return 0;
}

