#include <iostream>
#include <vector>
using namespace std;


int main() {
	int t;
	cin>>t;
	long long n,k,i;
	vector<long long> arr;
	while(t--)
	{
	    cin>>n;
	    arr.resize(n);
	    cin>>arr[0];
	    for(i=1;i<n;i++)
	    {
	           cin>>arr[i];
	           arr[i]+=arr[i-1];
	    }
	    
	    for( i=1;i<n;i++)
	        if(arr[n-1]-arr[i]==arr[i-1])
	        {
	                cout<<i+1<<"\n";
	                break;
	        }
	    if(n==1)
	    cout<<"1\n";
	   else if(i==n)
	    cout<<"-1"<<"\n";
	}
	return 0;
}