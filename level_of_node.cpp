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

node* addnode()
 {
    queue<node*> q;
    int n,k;
    node* root;
    cout<<"enter the number of nodes";
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

 int find_level(node* root,int k)
 {
 	if(root==NULL)
 		return -1;
 	if(root->data == k)
 		return 0;
 	int l = find_level(root->left,k);
 	if(l>=0)
 		return l+1;
 	int r = find_level(root->right,k);
 	if(r>=0)
 	return r+1;
 	return r;
 }

int main()
{
	int k;
	node * root = addnode();
	cout<<"enter the key of the node";
	cin>>k;
	cout<<find_level(root,k);
	return 0;
}