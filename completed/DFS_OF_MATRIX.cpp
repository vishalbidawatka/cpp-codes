#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


 void getcount(int row,int col, vector< vector<int> > &a)
 {
     if(row>=a.size() || col>=a[0].size() || a[row][col]==0)
       return ;
     a[row][col]=0;
     
     if(row!=0)
     {
         getcount(row-1,col,a);
     }
     
     if(row!=(a.size()-1))
     {
         getcount(row+1,col,a);
     }
     
     if(col!=0)
     {
         getcount(row,col-1,a);
     }
     
     if(col!=(a[0].size()-1))
     {
         getcount(row,col+1,a);
     }
     
     
 }


int main() {
        int n,m;
        string k;
        cin>>m>>n;
    vector< vector<int> > a;
    for(int i=0;i<m;i++)
    {
        cin>>k;
        vector<int> b;
        for(int j=0;j<n;j++)
        {
            
            b.push_back((int)k[j]-48);
        }
        a.push_back(b);
        b.resize(0);
    }
   
    //vector< vector<int> > visited(m,vector<int> (n));
    int c=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {   
                c++;
                getcount(i,j,a);
            }
            
           
             
        }
        
    }
    cout<<c;
    
    
    return 0;
}
