// Indraneel was here
#include<iostream>
using namespace std;



class vector{

  public:
	int s;
    int k;
    int *a=NULL;

  vector()
  {
   a = new int[10];
   s=10;
   k=0;

  }

  vector(int n,int x)
  {
  	s=2*n;

    a = new int[n*2];
    if(x!=0)
    	for(int i=0;i<n;i++)
    		a[i]=x;
    	k=n;

  }

  int size();
  void insert(int i,int x);
  int value(int i);
  void push_back(int i);
  void pop_back();
  void erase(int i);
  int front();
  int back();



};


  int vector :: size()
  {
  		return k;

  }

 

   int vector :: value(int i)
   {
   		return a[i];
   }
  
   void vector :: push_back(int i)
   {
      if(((k+1)/s)>0.8)
      {
      int *arr = new int[s*2];
      for(int j=0;j<k;j++)
      	arr[j]=a[j];
        delete[] a;
        a=arr;


 	 }

 	 k++;
 	 a[k-1]=i;

   }

   void vector :: pop_back()
   {
     k--;
    /* if((k/s)<0.2)
     {
  		int *arr = new int[s/2];
  		for(int i=0;i<k;i++)
  			arr[i]=a[i];
  		delete[] a;
  		a=arr;

     }*/

   }

   void vector :: insert(int i,int x)
 {

  if(i>k)
  {
    cout<<"invalid index";
    return;
  }
 	if((k+1)/s>0.8)
 	{
      int *arr = new int[k*2];
      for(int j=0;j<k;j++)
      	arr[j]=a[j];
        delete[] a;
        
        a=arr;

 	}

 	
 	
       int j=k-1;
 		while(j>=i)
 			{
 				a[j+1]=a[j];
 				j--;
 			}

 	

    j++;
    a[j]=x;
    k++;

     

  }



   void vector :: erase(int i)
   {

     for(int j=i;j<k-1;j++)
     {
       a[j]=a[j+1];

     }
     k--;

   }

  int vector :: front()
  {

   return a[0];
  }


   int vector :: back()
  {
    
   return a[k-1];

  }