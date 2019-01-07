#include<iostream>
#include<vector>
using namespace std;


void swap(long long * a,long long * b)
{
	long long temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(vector<long long> &a)
{
	//i is used to traverse the array 
	//low stores the starting location where next 0 is to be put
	//high stores the location where next 2 is to be placed
	long low=0,i=0,high = a.size()-1;
	while(i <= high)
	{
		if(a[i] == 0)
			swap(&a[i++],&a[low++]); //reference also works in vectors
		else
			if(a[i]==1)
				i++; // low and i will be different when we get first 1
		else
			if(a[i]==2)
				swap(&a[i],&a[high--]);
	}	

	for(auto p: a)
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