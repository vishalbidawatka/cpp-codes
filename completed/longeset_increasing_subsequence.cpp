#include<iostream>
#include<vector>
using namespace std;


 void lcs(vector<int> &a)
 {
 	int i,j,m=1;
 	
 	vector<int> l(a.size(),1);

 	for(i=1;i<a.size();i++)
 	{

 		for(j=0;j<i;j++)
 		{

 			if(a[j]<a[i])
 				l[i]=max(l[i],l[j]+1);

 			if(m<l[i])
 				m=l[i];

 				
 		}
 	}

    cout<<m<<" 	";

 }
 


int main()
{
 int n,k;
 cin>>n;
  vector<int> a;
   for(int i=0;i<n;i++)
 	{
 		cin>>k;
 		a.push_back(k);
 	}

  lcs(a);

}