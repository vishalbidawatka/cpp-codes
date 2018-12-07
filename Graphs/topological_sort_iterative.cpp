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

  void topo_sort()
  {
    int i;
    vector<int> b;  //to store the final result
    while(b.size()!=V)
    {
      for(i=0;i<V;i++)
      {
        if(a[i]==0)
        {
          a[i]=1;
         break;
        }
      }
      b.push_back(i);

     if(i!=V && l[i].size()>0)
      for(auto j : l[i])
         a[j]--;

   }

   for(auto j : b)
    cout<<j<<" ";

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