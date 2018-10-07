#include<iostream>
using namespace std;


int count_color(int n,int k)
{
	int total[n+1],diff[n+1];

	total[1]=1;
	total[2]=k+k*(k-1);
	diff[1]=k;
	diff[2]=k*(k-1);

	int i=3;
	while(i<=n)
	{
		diff[i]=total[i-1]*(k-1);
		total[i]=diff[i]+diff[i-1];
		i++;

	}

	return total[n];
}

int main()
{
  int n,k;
  cin>>n>>k;
 
 cout<<count_color(n,k);

return 0;
}