#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void euler_totient(int n)
{

  int j;

  vector<int> a;
  vector<int>:: iterator it;

    for(int i=2;i<n/2;i++) // to calculate all divisors of n
    {

     if(n%i==0)
      a.push_back(i);

    }
   

      for(int i=2;i<n;i++)
      {

          for(j=2;j<=i;j++)
          {
           
            if(i%j==0)
          {
               it = find(a.begin(),a.end(),j);

              if(it!=a.end())
              break;
           }

       }
        if(j==i+1)
        cout<<i<<"\t";         

      }



}


int main()
{

  int n;
  cin>>n;
   euler_totient(n);

  return 0;


}