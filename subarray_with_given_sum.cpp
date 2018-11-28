#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    long long n,s,j=0,result,i;
    vector<long long> arr;
    cin>>t;
    while(t--)
    {
        result = 0;
        cin>>n>>s;
        arr.resize(n);
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            result+=arr[i];
            if(result > s)
            {
                result-=arr[j];
                j++;
            }
            if(result == s)
            {
                cout<<j+1<<" "<<i+1<<"\n";
                break;
            }
        }
        if(i==n)
            cout<<"-1\n";
        
    }


	return 0;
}