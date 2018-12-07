#include<iostream>
#include <vector>
#define ll long long
using namespace std;

//basically the used formula is res+=min(max_left,max_right)-arr[i];

ll trapping_water(vector<ll> &arr)
{
	ll left=0,right=arr.size()-1; //to store the indices
	ll max_left=0,max_right=0; //to store the maximum height bar from left and right
	ll res=0;
	while(left<=right)
	{
		if(arr[left] < arr[right]) // need to check this else suppose decreasing order height
		{
			if(arr[left]>max_left)
				max_left = arr[left];
			else
				res+=max_left-arr[left];
			left++;
		}

		else
		{
			if(arr[right]>max_right)
				max_right = arr[right];
			else
				res+=max_right-arr[right];
			right--;
		}

	}
	return res;
}


int main()
{
	int t;
	ll n;
	vector<ll> arr;
	cin>>t;
	while(t--)
	{
		cin>>n;
		arr.resize(n);
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		cout<<trapping_water(arr)<<"\n";
	}
	return 0;
}