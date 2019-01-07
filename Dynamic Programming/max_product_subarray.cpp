 #include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

    int maxProduct(vector<int>& nums) {
        
        int maximum=nums[0],minimum=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(maximum,minimum);
            maximum=max(nums[i],maximum*nums[i]);
            minimum=min(nums[i],minimum*nums[i]);
            if(res<maximum)
                res=maximum;
            
        }
        return res;
    }



   int main()
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxProduct(arr);
        return 0;
    }