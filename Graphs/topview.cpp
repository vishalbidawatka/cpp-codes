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

void topView(struct node* root) 
{ 
    if (root == NULL) 
        return; 

    unordered_map<int, int> m;
    // m.first contains the horizontal distance and second contains the value printed corresponding to the distance
    queue<pair<node*, int> > q; 
    //q.second contains the horizontal value

    q.push(make_pair(root, 0)); 

    while (!q.empty()) { 
        pair<node*, int> p = q.front(); 
        node* n = p.first; 
        int val = p.second; 
        q.pop(); 

        
        if (m.find(val) == m.end()) { 
            m[val] = n->data; 
            printf("%d ", n->data); 
        } 

        if (n->left != NULL) 
            q.push(make_pair(n->left, val - 1)); 

        if (n->right != NULL) 
            q.push(make_pair(n->right, val + 1)); 
    } 
} 


int main()
{
    node * root = addnode();
    topView(root);
return 0;
}