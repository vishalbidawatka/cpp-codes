  #include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

void backtrack(vector<vector<int>> &result,vector<int> &nums,vector<int> v,int pos)
    {
        result.push_back(v);
        for(int i=pos;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            backtrack(result,nums,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> v;
        backtrack(result,nums,v,0);
        return result;
    }

     int main()
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
                cin>>arr[i];
        subsets(arr);
        return 0;
    }