#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void new_alphabetical_order(string s)
{
	string actual="abcdefghijklmnopqrstuvwxyz";
	int a[26]; // to store the 
	int n,z;
	string k;
	vector<string> b;
	for(int i=0;i<26;i++)
	{
		int j=s[i]-'a';
		a[j]=i;
	}
	cin>>n>>z;
	while(n--)
	{
		cin>>k;
		for(int i=0;i<k.length();i++)
		{
			k[i]=actual[a[k[i]-'a']];

		}
		b.push_back(k);
	}



 sort(b.begin(),b.end());
  k=b[z-1];
  for(int i=0;i<k.length();i++)
  {
  	k[i]=s[k[i]-'a'];
  }

 cout<<k;

}

int main()
{
	string s;
	cin>>s;
	new_alphabetical_order(s);

	return 0;
}