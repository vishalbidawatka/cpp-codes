#include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

void backtrack(vector<vector<int>> &result,vector<int> &nums,vector<int> v)
    {
        if(v.size()==nums.size())
        {
            result.push_back(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(find(v.begin(),v.end(),nums[i])==v.end())
            {
                v.push_back(nums[i]);
                backtrack(result,nums,v);
                v.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
     
        vector<vector<int>> result;
        vector<int> v;
        backtrack(result,nums,v);
        return result;
    }

    int main()
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
                cin>>arr[i];
        permute(arr);
        return 0;
    }