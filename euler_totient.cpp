#include<iostream>
#include<vector>
using namespace std;

void coprime(int n)
{
  vector<int> a(n+1,1);
  int j;
  for(int i=2;i<n;i++)
  {
    if(a[i]==0)
    continue;
    if(n%i==0)
    {
      j=1;
      while(j*i<n)
      {
        a[j*i]=0;
        j++;
      }
    }
    else
      cout<<i<<" ";
  }
}
int main()
{
  int n;
  cin>>n;
  coprime(n);

return 0;
}