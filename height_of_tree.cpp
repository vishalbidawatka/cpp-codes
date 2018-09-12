#include<iostream>
#include<vector>
using namespace std;

 int height(int* a,int n)
 {
 	if(n>=(sizeof(a)/sizeof(int)))
 		return 0;
 	int left,right;
 	left=2*+1;
 	right=2*n+1;
 	if(left<(sizeof(a)/sizeof(int)))
 	left=height(a,left);
    if(right<(sizeof(a)/sizeof(int)))
 	right=height(a,right);
 	return max(left,right);
 }



int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<height(a,0);

return 0;
}