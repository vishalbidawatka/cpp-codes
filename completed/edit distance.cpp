#include <cmath>
#include<string.h>
#include<string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int minDistance(string word1, string word2) {
        
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][0]=word1[0]==word2[0]?0:1;
            
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                    dp[0][j]=j;
                else if(j==0)
                    dp[i][0]=i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
      return dp[n][m];      
    }

    int main()
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        minDistance(s1,s2);
        return 0;
    }