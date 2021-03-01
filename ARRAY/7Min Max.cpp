// Q-Find maximum and minimum of an array using minimum number of comparisons.

#include<iostream>
using namespace std;
//to return 2 elements at once we will use class 
class Pair{
	public :
	int min;
	int max;
};
//we will compare 2 elements at a time and then result will be compared to min,max
Pair minMax(int a[],int n){	 
	Pair obj;		//object of class Pair to access min,max
	int i;			//i-use in comparing array element
	//if Array has 1 element
	//assign it as min and max both
	if(n==1)	
	{
		obj.min=a[0];
		obj.max=a[0];
		return obj;
	}
	else
	{
		//if no. of element are even
		if(n%2==0)
		{
			//assign first 2 element of array to min ,max accordingly
			if(a[0]>a[1])
			{
				obj.max=a[0];
				obj.min=a[1];
			}
			else
			{
				obj.max=a[1];
				obj.min=a[0];
			}
			i=2;	
		}
		//if no. of elements are odd
		//assign first element to both min and max
		else
		{	
			obj.min=a[0];
			obj.max=a[0];
			i=1;	
		}
		while(i<n-1)
		{
			if(a[i]>a[i+1]){
				if(a[i]>obj.max)
					obj.max=a[i];
				if(a[i+1]<obj.min)
					obj.min=a[i+1];
			}
			else{
				if(a[i+1]>obj.max)
					obj.max=a[i+1];
				if(a[i]<obj.min)
					obj.min=a[i];
			}
		i=i+2;
		}
		return obj;
	}
}
int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);	//No. of integers in Array
	
	Pair element=minMax(a,n);
	cout<<"\nMinimum Element : "<<element.min;
	cout<<"\nMaximum Element : "<<element.max;
}