#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int second,third,sum;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int first=0;first<(nums.size()-2) && nums.size()>2;first++)
        {
            
            second= first+1;
            third = nums.size()-1;
            while(second<third)
            {
                sum=nums[first]+nums[second]+nums[third];
                if(sum>0)
                    third--;
                else if(sum<0)
                    second++;
                else
                {
                    vector<int> clone={nums[first],nums[second],nums[third]};
                    result.push_back(clone);
                    while(second<(nums.size()-1) && nums[second]==nums[second+1])
                        second++;
                    while(third>0 && nums[third]==nums[third-1])
                        third--;
                    second++;
                    third--;
                }
            }
            while(first<(nums.size()-1) && nums[first]==nums[first+1])
                first++;
            
        }
       
        return result;
    }
    int main()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        threeSum(nums);

        return 0;
    }