#include<iostream>
#include<vector>
using namespace std;

//a[i][0] contains weight
//a[i][1] contains profit

int knapsack(vector< vector<int> > &a,int maximum)
{
	vector< vector<int> > dp(a.size(),vector<int> (maximum+1));
   
   for(int i=0;i<a.size();i++)
   {
   	  for(int j=1;j<=maximum;j++)
   	  {
 		if(i==0 && j>=a[i][0])
 			dp[i][j]=a[i][1];

   	    else if(j>=a[i][0])
   	  	  dp[i][j]= max(dp[i-1][j],a[i][1]+dp[i-1][j-a[i][0]]);

   	  	else if(i>0)
   	  		dp[i][j]=dp[i-1][j];

   	  }


   }


   	int j=maximum;
   	cout<<"included weights are";
   	for(int i=a.size()-1;i>0 && dp[i][j]>0 && j>0;i--)
	{
			if(dp[i-1][j]!=dp[i][j])
			{
				cout<<a[i][0]<<" ";
					j=j-a[i][0];
			}
    }

    cout<<"\n";

    return dp[a.size()-1][maximum];
}

int main()
{
	int n,maximum,p,w;
	cin>>n>>maximum;
	vector< vector<int> > a(n,vector<int>(2));
	int i=0;
	while(i<n)
	{
		cin>>w>>p;
		a[i][0]=w;
		a[i][1]=p;
		i++;
	}
	cout<<knapsack(a,maximum)<<"is the total profit";

	return 0;
}