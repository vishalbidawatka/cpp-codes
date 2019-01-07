#include <iostream>
#include <vector>
using namespace std;

long find_sum(vector<long> arr)
{
	long result = arr[0]; // for final result
	long max = 0;	//for temporary max

	for(int i=0;i<arr.size();i++)
	{
		max+=arr[i];
		if(max > result)
			result = max;
		if(max < 0)
			max = 0;
	}

	return result;

}

int main()
{
	long n;
	vector<long> arr;
	cout<<"enter the total elements";
	cin>>n;
	arr.resize(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	cout<<find_sum(arr);
}
