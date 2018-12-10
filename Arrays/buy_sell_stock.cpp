#include <iostream>
#include <vector>
using namespace std;

/*
The cost of stock on each day is given in an array A. 
Find all the days on which you buy and sell the stock 
so that in between those days you shouldn't have any loss
i/p-100 180 260 310 40 535 695
o/p- (0 3) (4 6)
*/

void buy_sell(vector<int> &arr)
{
    int max;
    int i=arr.size()-1;
    while(i>0 && arr[i-1]>arr[i])
        i--;
    max = i;
    i--;
    while(i>=0)
    {
        if(arr[i]>arr[max])
        {
            pair<int,int> foo = make_pair(i+1,max);
            result.push_back(foo);
            max = i;
        }
        i--;
    }
    pair<int,int> foo = make_pair(i+1,max);
    result.push_back(foo);
    
    for(i=result.size()-1;i>=0;i--)
    {
        cout<<"("<<result[i].first<<","<<result[i].second<<") ";
    }
    cout<<"\n";
}

int main() {
	int t,n;
	cin>>t;
	vector<int> arr;
	while(t--)
	{
	    cin>>n;
	    arr.resize(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        buy_sell(arr);
	}
	return 0;
}