 #include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

 int search(vector<int>& nums, int target) {
        
        if(!nums.size())
            return -1;
        int low=0,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else
            {
                if(target>nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
                    
            }
        }
        return -1;
    }



   int main()
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        search(arr);
        return 0;
    }