#include<iostream>
#include<vector>
using namespace std;

bool is_attacked(int i,int j,vector< vector<int> > &a)
{
	for(auto t : a[i]) //check each column for attacked
	  if(t==1)
	  	return true;

	for(int k=0;k<a.size();k++) //check each row for attacked
	 if(a[k][j]==1)
	  return true;

	 for(int k=0;k<i+j;k++) //checking diagonal x+y=1
	  if(a[k][i+j-k]==1)
	  	return true;

	  //for(int k=)  //checking diagonal x+y=-1

}

void nqueens(vector< vector<int> > &a,n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(is_attacked(i,j,a))
			 continue;
			a[i][j]=1;
			if(nqueens(a,n-1));
				return true;
			  a[i][j]=0;

		}
	}

	return false;

}

int main()
{
	int n;
	cin>>n;
	vector< vector<int> > a(n,vector<int> (n,0));
	nqueens(a,n);


	return 0;
}