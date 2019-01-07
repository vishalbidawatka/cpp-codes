#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    vector<long long int> a(1000000,0);
    long long int q,sum,l,j=2,r;
    cin>>q;
   a[2]=2;
    while(2*j<1000000)
        {
            a[2*j]=1;
            j++;
        }
        
    for(int i=3;i<1000000;i+=2)
    {
        if(a[i]==1)
            continue;
        j=2;
        a[i]=i;
        
        while(j*i<1000000)
        {
            a[j*i]=1;
            j++;
        }
        
        
    }
    
    while(q--)
    {
        sum=0;
        cin>>l>>r;
        
        for(int i=l;i<=r;i++)
        {
            if(a[i]!=1)
                sum+=a[i];
            
        }
        
        cout<<sum<<"\n";
    }
    
    
    
    
    
    
    
    
    return 0;
}

