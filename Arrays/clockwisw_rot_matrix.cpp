#include<iostream>
#include <vector>
using namespace std;


 void rotate(vector<vector<int>> &matrix)
 {
 	int n=matrix.size();
 	int temp;
 	for(int i=0;i<n/2;i++)
 	{
 		for(int j=i;j<n-1-i;j++)
 		{
 			temp = matrix[i][j];
 			matrix[i][j]=matrix[n-1-j][i];
 			matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
 			matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
 			matrix[j][n-1-i]=temp;
 		}
 	}
 }

 void display(vector<vector<int>> &matrix)
 {
 	for(auto a:matrix)
 	{

 		for(auto b:a)
 			cout<<b<<" ";
 		cout<<"\n";
 	}
 }
int main()
{
	int n;
	cout<<"enter the matrix size";
	cin>>n;
	vector<vector<int>> matrix(n,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	rotate(matrix);
	display(matrix);
	return 0;
}