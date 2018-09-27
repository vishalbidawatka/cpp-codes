#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
# define MOD 1000000007
using namespace std;

//Time Complexity-O(n)
//Space Complexity-O(1)
unsigned long long int multiply(unsigned long long int n)
{
int a[2][2]={{1,1},{1,0}};
unsigned long long int w,x,y,z;
    int m[2][2] = {{1,1},{1,0}};


   while(n>0) //keep multiplying a to m until n reaches zero
   {
       
           w = ((m[0][0]*a[0][0])%MOD+(m[0][1]*a[1][0])%MOD)%MOD;
           x = ((m[0][0]*a[0][1])%MOD+(m[0][1]*a[1][1])%MOD)%MOD;
           y = ((m[1][0]*a[0][0])%MOD+(m[1][1]*a[1][0])%MOD)%MOD;
           z = ((m[1][0]*a[0][1])%MOD+(m[1][1]*a[1][1])%MOD)%MOD;
           n--;
           m[0][0]=w;
           m[0][1]=x;
           m[1][0]=y;
           m[1][1]=z;
   }
           
     
return m[0][0];


}

int main() {
    
    unsigned long long int n,t,a;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
    
        a= multiply(n-2);  //as it calculates f(n+2)
        
       
    cout<<a<<"\n";
    }
    
    return 0;
}
