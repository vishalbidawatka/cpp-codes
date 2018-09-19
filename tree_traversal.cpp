#include<iostream>
#include<queue>
using namespace std;

struct node{
  
    int data;
    node *left;
    node *right; 

    node(int k)
    {

        data=k;
        left=NULL;
        right=NULL;
    }

};

 void inorder(node* root)
 {
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

 }

 void preorder(node *root)
 {
    if(root==NULL)
        return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);

 }

 void postorder(node *root)
 {
    if(root==NULL)
        return;
    cout<<root->data;
    postorder(root->left);
    postorder(root->right);

 }


 node* addnode()
 {
    queue<node*> q;
    int n,k;
    node* root;
    cin>>n; //n defines the number of nodes
    while(n--)
    {
        cin>>k; //data value of the node

        node* a = new node(k);
       
       if(!q.empty())
       { 
        if(q.front()->left==NULL)
        {
            q.front()->left=a;
        }

        else if(q.front()->right==NULL)
        {
            q.front()->right=a;
            q.pop();
        }

       }

       else
       {
        root=a;
       }



            q.push(a);
    }

    return root;
 }


int main()
{
    node* root=addnode();
    inorder(root);
    preorder(root);
    postorder(root);

    return 0;
}