#include<iostream>
#include<vector>
using namespace std;


long find_sum(vector<int> arr)
{
	long inclusive = arr[0]; // to determine the sum including the current element
	long exclusive = 0; // to determine the sum excluding the current element
	long temp; // temporary variable

	for(int i=1;i<arr.size();i++)
	{
		temp = inclusive;
		inclusive = max(exclusive+arr[i],inclusive);
		exclusive = temp;
	}

	return inclusive;
}

int main()
{
	long n;
	vector<int> arr;
	cout<<"enter the number of elements";
	cin>>n;
	arr.resize(n);
	for(long i=0;i<n;i++)
		cin>>arr[i];
	cout<<find_sum(arr);


	return 0;
}