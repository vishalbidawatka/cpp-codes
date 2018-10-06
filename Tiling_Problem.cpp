#include<iostream>
using namespace std;


int tiling(int n)
{
	if(n==1 || n==2)
	 return n;

	return tiling(n-1)+ tiling(n-2);


}

int main()
{
	int n;
	cin>>n;
	cout<<tiling(n);

return 0;
}