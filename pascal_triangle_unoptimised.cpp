#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,i,j;
	vector<int> arr;
	vector<int> clone;
	clone.push_back(1);
	arr.push_back(1);
	cin>>n;
	for(i=2;i<=n;i++)
	{
		clone.swap(arr);
		arr.resize(i);
		arr[0]=arr[i-1]=1;
		for(j=1;j<(i-1);j++)
			arr[j]=clone[j-1]+clone[j];
	}
	for(auto a:arr)
		cout<<a<<" ";
	return 0;
}