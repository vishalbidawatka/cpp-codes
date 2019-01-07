#include <cstdio>
#include <algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
using namespace std;

vector<bool> visited;
vector<int> permutation;
vector<int> final;

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
    
  bool topo_sort()    //(vector<int> &final,vector<int> permutation,vector<bool> &visited)
  {
      if(final.size()==permutation.size())
          return true;
      
      int i=permutation[(final.size())-1];
      list<int>::iterator it;
      int k=V;
      
      for(it=l[i].begin();it!=l[i].end();it++)
      {
          if(visited[*it]==false && (*it)>permutation[final.size()] && (*it)<k)
            {
                visited[*it]=true;
                final.push_back(*it);
                if(topo_sort())   //(final,permutation,visited)
                    return true;
            }
          
      }
      visited[final.back()]=false;
      if(final.size()>1)
      {
          final.pop_back();
      
      if(topo_sort())     //(final,permutation,visited))
          return true;
      }
      
      return false;
  }
    
    
};


int main()
{
    int n,m,a,b;
    cin>>n>>m;
    Graph g(n+1);
    visited.resize(n+1);
    while(m--)
    {
        cin>>a>>b;
        g.addnode(a,b);
        
    }
    while(cin>>a)
        permutation.push_back(a);
    
    int i=0;
    while(i<permutation.size()-1)
    {
        final.push_back(permutation[i]);
        visited[permutation[i]]=true;
        i++;
    }
    
   if(!g.topo_sort())
        cout<<"-1";
    else{
        for(auto result : final)
          cout<<result<<" ";
     
        }
    return 0;
}


