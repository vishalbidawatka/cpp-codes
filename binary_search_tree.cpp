#include<iostream>
#include<queue>
#include<unordered_map>
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

void BST_INSERT(node* root,int k) //iterative insertion in BST
{
    node* temp = root;
    while(temp!=NULL)
    {
        if(k<temp->data && temp->left == NULL)
        {   
            temp->left = new node(k);
            break;
        }
        else if(k< temp->data && temp->left != NULL)
            temp = temp->left;
        else if(k>temp->data && temp->right == NULL)
        {
            temp->right = new node(k);
            break;
        }
        else if(k > temp->data && temp->right != NULL)
            temp = temp->right;
        else 
            break;
    }
}

node* addnode()
{
    int n,k;
    node* root = NULL;
    cout<<"enter the number of nodes";
    cin>>n;

    while(n--)
    {
        cin>>k;
        if(root==NULL)
            root = new node(k);
        else
            BST_INSERT(root,k);
    }   
    return root; 
}

void preorder(node *root)
 {
    if(root==NULL)
        return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);

 }

 node* BST_DELETE(node* root,int k)
 {
    if(root == NULL)
        return root;
    if(k < root->data)
        root->left = BST_DELETE(root->left,k);
    else if(k > root->data)
        root->right = BST_DELETE(root->right,k);
    else
    {
        node*temp;
        if(root->left == NULL) 
        {
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        }
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        temp = root->right;
        while(temp!=NULL)  //find inorder successor
        {
            if(temp->left == NULL)
                break;
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = BST_DELETE(root->right,temp->data);

    }
    return root;
 }

 int main()
{
    node * root = addnode();
    preorder(root);
    BST_DELETE(root,4);
    cout<<"\n";
    preorder(root);
    return 0;
}