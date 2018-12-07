#include<iostream>  
#include<map>
#include<list>
#include<string.h>
using namespace std;

class StringBuilder{

 list<char*> l;

  public :
  



  void stringInitialize(char* name)
  {
    l.push_back(name);
  }

  int *generate_index(char* substring) //to store the prefix and suffix
  {
    int m = strlen(substring);
  	int *store_index=new int[m];

  	int j=0; //used to store index
  	for(int i=1;i<m;)
  	{
  		if(substring[i]==substring[j])
  		{
  			store_index[i]=j+1;
  			j++;
  			i++;
  		}

  		else if(j!=0)
  		{
  			j=store_index[j-1];
  		}

 	    else
 	    {
 	    	store_index[i]=0;
 	    	i++;
 	    }

  	}

  	return store_index;
  }

  int findSubstring(StringBuilder object_name,char * substring)
  {
     int *store_index = generate_index(substring);
     int index=0;
     int start;  // to store the final result i.e. index
     int length = 0;
     int m = strlen(substring);
     for( auto a: object_name.l){
        int n = strlen(a);
        for(int i=0;i<n && index<m;)
        {
          if(substring[index]==a[i])
          {
            if(index==0)
            start=i;
            index++;
            i++;
          }

      else if(index!=0)
      {
        index = store_index[index-1];
      }

      else
      {
        i++;
      }

     }

     if(index==m)
      return start;
    length +=n;
  }
         
  return -1;

}


  void stringAppend(StringBuilder s1,StringBuilder s2)
  { 
    for(auto a : s1.l)
      l.push_back(a);

    for(auto a : s2.l)
      l.push_back(a);
  }

  void print()
  {
   
   for(auto a : l)
     cout<<a;
 }

};


StringBuilder stringInitialize(char* name)
{
 StringBuilder s1;
 s1.stringInitialize(name);
 return s1;

}

int findSubstring(StringBuilder s1,char* substring)
{
	return s1.findSubstring(s1,substring);

}

StringBuilder stringAppend(StringBuilder s1,StringBuilder s2)
{
  StringBuilder s3;
  s3.stringAppend(s1,s2);
  return s3;
}


int main()
{ 
StringBuilder s1 = stringInitialize("hello");
StringBuilder s2 = stringInitialize("world");
StringBuilder s3 = stringAppend(s1,s2); 
StringBuilder s4 = stringAppend(s3,s1);
cout<<findSubstring(s4,"oworldhe");

return 0;
}