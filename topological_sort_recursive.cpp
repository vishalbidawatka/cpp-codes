#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph{
 
  int V;
  list<int> *l;   //used to store the graph
  vector<int> a;  //used to store indegree

public:
  Graph(int n)
  {
  	V=n;
  	l=new list<int>[n];
    a.resize(n);
    
  }

  void addnode(int u,int v)
  {
  	l[u].push_back(v);
   	a[v]+=1;
  }

  void topo_helper(int n,vector<int> &a,list<int> &b)
  {
    if(a[n]!=1)
    {
      a[n]=1;
      for(auto i : l[n])
        topo_helper(i,a,b);
      b.push_front(n);

    }
  }

  void topo_sort()
  {
    vector<int> a(V); //to store the visited
    list<int> b; //to store the final output
    for(int i=0;i<V;i++)
    {
      topo_helper(i,a,b);
    }

    for(auto i : b)
      cout<<i<<" ";

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
  
 	g.topo_sort();

	return 0;
}