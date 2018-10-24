#include<iostream>
#include<vector>
# define MAX 1000000
using namespace std;

long long int i=-1,j=-1;

void insert_max(int *b,int n)
{

    int temp;

        while(n>0)
       {
    
       if(n>0 && b[(n-1)/2]<b[n])
       {

           temp=b[(n-1)/2];
           b[(n-1)/2]=b[n];
           b[n]=temp;

       }

       else
           break;
       n=(n-1)/2;


    }


}

  

   void insert_min(int *a,int n)
   {
       int temp;



       while(n>0)
       {
    
       if(n>0 && a[(n-1)/2]>a[n])
       {

           temp=a[(n-1)/2];
           a[(n-1)/2]=a[n];
           a[n]=temp;

       }
       else 
           break;
       n=(n-1)/2;


    }

   }

   void min_heapify(int *a,int n)
  {
      int l=2*n+1;
      int r=2*n+2;
      int min=n;
      int temp;

      if(l<=i && a[l]<a[n])
          min=l;

       if(r<=i && a[r]<a[min])
          min=r;

      if(min!=n)
      {

          temp=a[n];
          a[n]=a[min];
          a[min]=temp;
          min_heapify(a,min);

      }




  }
  

void max_heapify(int *b,int n)
 {
      int l=2*n+1;
      int r=2*n+2;
      int max=n;
      int temp;

      if(l<=j && b[l]>b[n])
          max=l;

       if(r<=j && b[r]>b[max])
          max=r;

      if(max!=n)
      {

          temp=b[n];
          b[n]=b[max];
          b[max]=temp;
          max_heapify(b,max);

      }




  }
  



int main()
{  
   int k,n,c;
   double median;
    int a[MAX]; //min-heap
    int b[MAX]; //max-heap
   cin>>c;


   while(c--)
  {
       cin>>k;
     
       if(i==-1 && j==-1)
       {

          i++;
          a[i]=k;
          
       }

      else if(k<median)
      {  
          j++;
          b[j]=k;
          
        insert_max(b,j);


      }

      else
      {
          i++;
         a[i]=k;
         insert_min(a,i);

      }

       if((i-j)>1)
       {
            

               j++;
               b[j]=a[0];
               a[0]=a[i];
               i--;
               

               min_heapify(a,0);
               insert_max(b,j);

              
               
               
       }

       else if((j-i)>1)
       {

           
           i++;
           a[i]=b[0];
           b[0]=b[j];
           j--;

      
           insert_min(a,i);
           max_heapify(b,0);

           

               


       }
      

           if(i==j)
               {
                   median =(double)(a[0]+b[0])/2;
                   //median*=1.0;
                   printf("%.1f\n",median);
               }
           else
           {

               median = (i>j ? a[0] : b[0]);

               //median*=1.0;
               printf("%.1f\n",median);
           }


     

  }

    return 0;

}