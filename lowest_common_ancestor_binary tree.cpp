#include<iostream>
#include<queue>
using namespace std;

//assuming that the element already exist in the tree
//Time Complexity - O(n)
//Space Complexity - O(1)

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

 node * lca(int a,int b,node * root)
 {
    if(root==NULL)
        return NULL;
    if(a==root->data)
        return root;

    if(b==root->data)
        return root;

    node * l = lca(a,b,root->left);
    node * r = lca(a,b,root->right);

    if(l && r) //if left and right subtree return non-null value that means root is the ancestor
        return root;

    if(l==NULL)    //else the one who is parent is the ancestor
     return r;
     return l; 



 }



int main()
{
	 node * root=addnode();
	 int a,b;
	 cin>>a>>b;
	 root=lca(a,b,root);
     cout<<root->data;
     

	return 0;
}