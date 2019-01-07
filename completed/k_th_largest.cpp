#include<iostream>
#include<cstdlib>
using namespace std;

int find_k_smallest(int input[], int k, int left, int right) {
	if(left==right)
		return input[left];

	int p = rand()%(right-left);  //calculate random value
	p+=left;

	int temp = input[right];
	input[right] = input[p];  //move pivot to the last place
	input[p] = temp;
	p = right;

	int low = left-1; 
	int high = low+1;
	
	while(high<right)  // traverse until we reach end and then place pivot at each position
	{

		if(input[high]>input[p]) //move ahead until value at high greater than pivot
			high++;

		else{     			//else swap low and high
			low++;
			temp = input[low];
			input[low] = input[high]; 
			input[high] = temp;
			high++;
		}
	}

	low+=1;
	temp = input[low];
	input[low] = input[p];  //place pivot at it's position
	input[p] = temp;
	if(low==k-1)
		return input[low];
	if(low<k-1)
	  return find_k_smallest(input,k,low+1,right); // call with higher array

	return find_k_smallest(input,k,left,low-1);  // call with lower array
	
		
}
int main() {
   
   	int n,k;
   	cin>>n>>k;
   	int input[n];  //input array
   	int i=0;
   	while(i<n)
   	{
   		cin>>input[i];  
   		i++;
   	}

	int value = find_k_smallest(input,k,0,n-1);
	cout<<value;
	
	return 0;
}