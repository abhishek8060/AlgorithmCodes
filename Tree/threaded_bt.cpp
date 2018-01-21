 #include<bits/stdc++.h>
using namespace std;
struct thbt{
int data;
thbt *left;
thbt *right;

};
thbt* newnode(thbt* root,int data)
{
thbt *tmp=new thbt();
tmp->data=data;
tmp->left=NULL;
tmp->right=NULL;
return tmp;
}
void inorder_thbt(thbt* root)
{
thbt *cur,*pre;
cur=root;


if (root==NULL)
  return;

while(cur!=NULL)
{
  if (cur->left==NULL)
  {
    cout<<cur->data<<" ";
    cur=cur->right;
  }

  else
   {
    pre=cur->left;

    while(pre->right!=NULL && pre->right!=cur)
      pre=pre->right;

    if(pre->right==NULL){
       pre->right=cur;
       cur=cur->left;
    }

    else {
    pre->right=NULL;
    cout<<cur->data<<" ";
    cur=cur->right;
    }

   }
  }

}

int main(){
thbt *root=NULL;
root=newnode(root,1);
root->left=newnode(root,2);
root->right=newnode(root,3);
root->left->left=newnode(root,4);
root->left->right=newnode(root,5);

inorder_thbt(root);
cout<<endl;


return 0;
}
                                                                                                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                                                               
          