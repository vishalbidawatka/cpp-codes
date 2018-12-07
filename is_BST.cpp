 #include<iostream>
#include<queue>
using namespace std;

//A code to check whether given binary tree is BST

struct Node{
  
    int data;
    node *left;
    node *right; 

    Node(int k)
    {

        data=k;
        left=NULL;
        right=NULL;
    }

};

  bool BST_helper(Node* node,int min,int max)
     {
         if(node==NULL)
             return true;
        
         
         if(node->data>max || node->data<=min)
          return false;
         
        return (BST_helper(node->left,min,node->data) && BST_helper(node->right,node->data,max));
       
         
     }



     Node* addnode()
 {
    queue<Node*> q;
    int n,k;
    Node* root;
    cin>>n; //n defines the number of nodes
    while(n--)
    {
        cin>>k; //data value of the node

        Node* a= new Node(k);
       
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
    Node* root=addnode();
    bool r= BST_helper(root,INT_MIN,INT_MAX);
    r==true?cout<<"yes":cout<<"no";
    
    return 0;
}