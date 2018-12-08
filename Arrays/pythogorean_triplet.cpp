#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

bool find_triplet(vector<int> &arr)
{
    //recieved an array after squaring all of it's elements

    sort(arr.begin(),arr.end()); //sort
    ll left,right;
    for(ll i=arr.size()-1;i>1;i--)  
    { 
        left = 0;
        right = i-1;
        while(left < right) //apply meet in middle algorithm
        {
            if(arr[left]+arr[right]<arr[i])
                left++;
            else if(arr[left]+arr[right]>arr[i])
                right--;
            else 
                return 1;
        }
    }
    
    return 0;
}


int main()
{
	int t;
	ll n;
	vector<int> arr;
	cin>>t;
	while(t--)
	{
		cin>>n;
		arr.resize(n);
		for(ll i=0;i<n;i++)
		{
		    cin>>arr[i];
		    arr[i]*=arr[i];
		}
		if(find_triplet(arr))
			cout<<"Yes\n";
		else 
			cout<<"No\n";
	}
	return 0;
}