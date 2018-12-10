#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> r;
        for(int i=0;i<nums.size();i++)
            nums[abs(nums[i])-1]*=-1;
      
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                r.push_back(i+1);
        
        return r;
    }

    int main()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        vector<int> ret = findDisappearedNumbers(nums);
        for(auto a: ret)
            cout<<a<<" ";
        return 0;
    }


