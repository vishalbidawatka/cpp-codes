#include <cmath>
#include <cstdio>
#include <vector>
#include<stack>
#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    
    ll int n,area,maxarea=0,j;
    cin>>n;
    vector<int> a(n);
    stack<int> s;
        
    ll int i=0,k;
    
    while(i<n)
    {
        cin>>a[i];
       if(s.empty() || a[s.top()]<=a[i])
           s.push(i);
        else 
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                j=s.top();
                s.pop();
                if(!s.empty())
                area=(i-(1+s.top()))*a[j];
                else
                    area=a[j]*(i-j);
                if(area>maxarea)
                    maxarea=area;
                
            }
            s.push(i);
        }
        i++;
            
        
        
    }
    
    
    while(!s.empty())
    {
        
        j=s.top();
        s.pop();
        if(!s.empty())
         area=(i-j)*a[j];
            else
             area=a[j]*i;
       if(area>maxarea)
           maxarea=area;
    }
    cout<<maxarea;
    
    return 0;
}

