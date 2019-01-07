 #include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int third,four;
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;
        for(int first=0;first<nums.size()-3;first++)
        {
            
            for(int second=first+1;second<nums.size()-2;second++)
            {
                
                third=second+1;
                four = nums.size()-1;
                while(third<four)
                {
                    if((nums[first]+nums[second]+nums[third]+nums[four])==target)
                   {
                    vector<int>clone={nums[first],nums[second],nums[third],nums[four]};
                    result.push_back(clone);
                    while(third<four && nums[third]==nums[third+1])
                        third++;
                    while(third<four && nums[four]==nums[four-1])
                        four--;
                 
  
                    third++;
                    four--;
                    
                   }
                else if((nums[first]+nums[second]+nums[third]+nums[four])<target)
                        third++;
                else 
                    four--;

                }
                while(second<nums.size()-1 && nums[second]==nums[second+1])
                second++;
            }
            while(first<nums.size()-1 && nums[first]==nums[first+1])
                first++;
        }
        
        return result;
    }




   int main()
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        maxArea(arr);
        return 0;
    }