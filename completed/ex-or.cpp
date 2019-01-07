#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void cal_ex_or(int k)
{
	    while(k>0)
		{
			a.push_back(k%2);
			k=k/2;

		}

}

 void ex_or(unordered_map< int,vector<int> > &a)
 {

 }

int main()
{
	int n,k;
	cin>>n;
	unordered_map< int,vector<int> > a;
	vector<int> b;
	while(n--)
	{
		cin>>k;
		a=k;
		 while(a>0)
		{
			a[k].push_back(a%2);
			a=a/2;

		}

	}

	cin>>k;
	 while(a>0)
		{
			b.push_back(a%2);
			a=a/2;

		}

		unordered_map< int, vector<int> >:: it;
		it=a.begin();
		while(i)



	return 0;

}