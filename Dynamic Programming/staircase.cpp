#include<iostream>
#include<vector>
using namespace std;


long staircase(long n)
{
	vector<long> clone(n+1);
	clone[1]=1;
	clone[2]=2;
	for(long i=3;i<=n;i++)
	{
		clone[i]=clone[i-1]+clone[i-2];

	}
	return clone[n];
}


int main()
{
	long n;
	cout<<"enter the number";
	cin>>n;
	cout<<staircase(n);
	return 0;
}