 #include<iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        if(!grid.size() || grid[0][0]==1)
            return 0;
        int i,j;
        int  r=grid.size();
        int c=grid[0].size();
        for(i=0;i<c;i++)
        {
            if(grid[0][i]==1)
                break;
            grid[0][i]=1;
        } 
               
        for(;i<c;i++)
            grid[0][i]=0;
            
        for(i=0;i<r;i++)
        {
            if(grid[i][0]==1)
                break;
            grid[i][0]=1;
        }
        for(;i<r;i++)
            grid[i][0]=0;
            
        for(i=1;i<r;i++)
            for(j=1;j<c;j++)
            {
                if(grid[i][j]==1)
                    grid[i][j]=0;
                else
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        return grid[r-1][c-1];
    }


   int main()
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int> (n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        cout<<uniquePathsWithObstacles(arr);
        return 0;
    }