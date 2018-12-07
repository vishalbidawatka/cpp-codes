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

node * swap(node * root)
{
	if(root==NULL)
		return NULL;

	node * temp;
	temp=root->left;
	root->left=root->right;
	root->right = temp;

	swap(root->left);
	swap(root->right);
	return root;


}

void print(node * root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
	
}

int main()
{
    node* root=addnode();
    root=swap(root);
    print(root);

    return 0;

}