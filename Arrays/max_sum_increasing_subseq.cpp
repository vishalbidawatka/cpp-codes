#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    long long n,i,k,maximum;
    vector<long long> arr;
    while(t--)
    {
        cin>>n;
	    arr.resize(n);
        cin>>arr[0];
        maximum = arr[0];
	    for(i=1;i<n;i++)
        {
            cin>>arr[i];
            k = arr[i];
            for(j=(i-1);j>=0;j--)  // need to traverse whole array as it may fail in 4 1 1 1 5
            {
                if(arr[j]<=k)
                  arr[i]=max(arr[i],k+arr[j]); //updated value of arr[i] for each j
                if(arr[i]>maximum)
                    maximum = arr[i];
            }
        

        }
        cout<<maximum<<"\n";
    }
 return 0;
}