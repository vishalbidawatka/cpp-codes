#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
        int t,n,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        queue<int> first;
        cin>>a;
        cin>>b;
        first.push(a+b);
        first.push(a-b);
        n-=2;
        
        while(n--)
        {
            cin>>a;
          
          int j=first.size();
          while(j--)   
         {
             int p=first.front();
             first.pop();
             first.push(p+a);
             first.push(p-a);
         }
            
        }  
      
        int flag=0;
        
        while(!first.empty())
        {
            int p = first.front();
            if(p==k)
            {
                flag=1;
                cout<<"YES\n";
                break;
            }
            first.pop();
        }
        if(flag==0)
            cout<<"NO";
        
    }
    
    
    return 0;
}
