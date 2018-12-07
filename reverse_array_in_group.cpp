#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	long long int k,n,i,j,temp,a;
	vector<long long> arr; //used to store input array
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    arr.resize(n);
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	        
	   for(i=0;i<n;i+=k)
	   {
	   	   j=i;
	   	   a=1;
	   	   if((i+k)>n) //if it exceeds array size
	   	   		k = n-i;
	       	 while(j<(i+k-a)) //swap with the corresponding element
	       	{
	        	temp = arr[j]; 
	        	arr[j] = arr[i+k-a]; // a is used to decrement end position each time
	         	arr[i+k-a] = temp;   
	         	j++;
	         	a++;
	        }
	  	 } 
	    for(i=0;i<n;i++)
	   		cout<<arr[i]<<" ";
	   	cout<<"\n";
	   
	   
	}
	return 0;
}

