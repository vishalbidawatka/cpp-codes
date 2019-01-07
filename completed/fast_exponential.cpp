#include<iostream>
#include<time.h>
using namespace std;



void fast_exp(int base, int power)
{

long long int result=1;



 while(power>0)
 {
  if(power%2==0)
  {
   power/=2;
   base*=base;

  } 

  else

   {
   	result*=base;
   	power-=1;
   }




}
cout<<result;


}



int main()
{

	int base,power;
  tm time;
	cin>>base>>power;
	fast_exp(base,power);

cout<<time.tm_sec;
return 0;

}