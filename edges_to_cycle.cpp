#include <cmath>
#include <cstdio>
#include <algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
//#include<pair>
using namespace std;

stack<int> final;  //to store the final output
list<int> *actual;
int total; // to store the final result

class Graph{
 
 int V;
 list<int> *l;

public:
  Graph(int a)
  {
      V=a;
      l=new list<int>[a];
      
  }

  void addnode(int u,int v)
  {
      l[u].push_back(v);
       
  }
    
   void DFS_helper(int i,stack<int>&final,vector<int> &visited)
  {    
    if(visited[i]!=1)
    {
      visited[i]=1;
      
      for(auto a:l[i])
        DFS_helper(a,final,visited);
      final.push(i);
        
    }
  }
    
  void DFS()
  {
    vector<int> visited(V,0); //to keep track of visited vertex
    
    for(int i=1;i<V;i++)
    {
      DFS_helper(i,final,visited);
    }
  }

  void reverse()
  {
      list<int> *clone=new list<int>[V];
      for(int i=1;i<V;i++)
      {
          for(auto a:l[i])
              clone[a].push_back(i);
      }
      actual = l;
      l = clone;
  }



  void component_detector(int i,vector<int> &visited,set<int> &cycle)
 {
     if(visited[i]!=1)
    {
      visited[i]=1;
      cycle.insert(i);
      for(auto a:l[i])
        component_detector(a,visited,cycle);
    }
     
 }
    
    void final_function(int count)
    {
        
        /*for(int c: l[count])
        {
            l[count].pop_front();
            total++;
            final_function(c);
        }*/
      
        while(l[count].size())
        {
            int c=l[count].front();
            total++;
            l[count].pop_front();
            final_function(c);
            
            
        }
    }


 int DFS_final()
 {
    
    vector<int> visited(V,0); //to keep track of visited vertex
     
   
    while(!final.empty())
     {
         int a=final.top();
         final.pop();
         if(visited[a]==0)
         {  
             set<int> cycle; //used to store each connected component
             map< pair<int,int>, bool> visited_edge;
             component_detector(a,visited,cycle);
             
             
             if(cycle.size()>1)
               for(int count : cycle)
                 final_function(count);   
             
         }

     }
     return total;

 }
    
};



int main()
{
    
    int e,v,a,b,t;
    cin>>t;
    while(t--)
    {
        
        total=0;
    cin>>v>>e;
    Graph g(v+1);
    actual = new list<int>[v];
    while(e--)
    {
        cin>>a>>b;
        g.addnode(a,b);
    }
    g.DFS();
    g.reverse();
    cout<<g.DFS_final()<<"\n";
    }
     return 0;
}