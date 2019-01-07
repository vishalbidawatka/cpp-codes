#include<iostream>
#include <vector>
using namespace std;

void sort_array(vector<long long>& arr)
{
	vector<long long> count(3,0);
	for(long long i=0;i<arr.size()-1;i++)
		count[arr[i]]++;
	for(long long i=0;i<count[0];i++)
		arr[i]=0;
	for(long long i=count[0];i<(count[1]+count[0]);i++)
		arr[i]=1;
	for(long long i=(count[1]+count[0]);i<arr.size();i++)
		arr[i]=2;

	for(auto p: arr)
		cout<<p<<" ";
}

int main()
{
	long long n,i;
	vector<long long> arr;
	cin>>n;
	arr.resize(n);
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort_array(arr);

	return 0;
}