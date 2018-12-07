#include<iostream>
using namespace std;

 bool is_attacked(vector< vector<int> > &a,int row,int col)
 {
 	int i,j;

 	for(i=0;i<col;i++)
 		if(a[row][col]==1)
 			return true;


 	for(i=row,j=col,i>=0,j>=0;i--,j--)
 	   if(a[i][j]==1)
 	     return true;

 	for(i=row,j=col,i<n,j>=0;i++,j--)
 	   if(a[i][j]==1)
 	     return true;     	

 }

 void print_queen(vector< vector<int> > &a)
 {
 	cout<<"[";
 	for(auto b : final)
 		cout<<b<<" ";
 	cout<<"] ";
 	

 }




bool nqueen(vector< vector<int> > &a,vector<int> &final,int col)
{
	if(col==a.size())
	{
		print_queen(a);
		return true;
	}
 	for(int i=0;i<n;i++)
 	{
 	  if(!is_attacked(col))
 	  {
 	  	a[i][j]=1;
 	  	final[i]=j+1;
 	  	if(!is_attacked(a,col+1))
 	  		return true;
 	  	a[i][j]=0;
 	  	final[i]=0;

 	  }

 	  return false;
}

int main()
{
	int n;
	cin>>n;
	vector<int> final;
	vector< vector<int> > a(n,vector(n));
	if(!nqueen(a,final,0))
		cout<<"-1";
return 0;
}