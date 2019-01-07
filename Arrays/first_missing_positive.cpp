 #include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int firstMissingPositive(vector<int>& nums) {
        
        int low=0,high=nums.size()-1,temp;
        while(low<high)
        {
            if(nums[low]<1)
            {
                temp=nums[low];
                nums[low]=nums[high];
                nums[high]=temp;
                high--;
            }
            else
                low++;
        }
        for(int i=0;i<low;i++)
            if(nums[i]<low && nums[nums[i]]>0)
                nums[nums[i]]*=-1;
        for(int i=0;i<low;i++)
            if(nums[i]>0)
                return i+1;
        return low+1;
    }



   int main()
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<firstMissingPositive(arr);
        return 0;
    }