#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<vector>
using namespace std;

//Adjacency list using array of list

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

 
  void DFS_helper(int i,vector<int>&final,vector<int> &visited)
  {
    if(visited[i]!=1)
    {
      visited[i]=1;
      final.push_back(i);
      for(auto a:l[i])
        DFS_helper(a,final,visited);
    }
    
  }


  void DFS()
  {
    vector<int> visited(V,0); //to keep track of visited vertex
    vector<int> final;  //to store the final output
    for(int i=0;i<V;i++)
    {
      DFS_helper(i,final,visited);
    }

    for(auto a:final)
      cout<<a<<" ";
  }

};


int main()
{
	
	int e,v,a,b;
	cin>>v>>e;
	Graph g(v);
	while(e--)
	{
		cin>>a>>b;
		g.addnode(a,b);
	}
  
 	//g.display();
  g.DFS();

 	return 0;
}