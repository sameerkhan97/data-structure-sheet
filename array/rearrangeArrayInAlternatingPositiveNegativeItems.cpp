/*Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative
 and vice-versa maintaining the order of appearance.Number of positive and negative numbers need not be equal. If there are more positive 
 numbers  they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.
Examples : 
Input:  arr[] = {1, 2, 3, -4, -1, 4}                Output: arr[] = {-4, 1, -1, 2, 3, 4}
Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}   output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0} */

#include <iostream>
using namespace std;
 
int main() {
	int a[]={1,2,3,-4,-1,4};
	int n=6;
	cout<<"\nBefore : ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
 
	cout<<"\n \n";	
	int i=0,j=n-1;
	//traversing array to move all the positive element at last and all the negative element at start
    	while(i<=j)
	{
	        //if at start we have positive and at end we have negative element then swapp
		if(a[i]>0 && a[j]<0)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
        	//if in start we have negative and in end we have positive element then no need of swapping  
		else if(a[i]<0 && a[j]>0)
		{
			i++;
			j--;
		}
        	//if start element is negative then move to next element
		else if(a[i]<0)
			i++;
		else if(a[j]>0)
			j--;
	}
	cout<<"\nAfter : ";
	//after sorting all elements i will be pointing to start of positive elements
        //if i point to start or end of array means array has all positive or all negative numbers
        if(i==0 || i==n)
	{
		for(int m=0;m<n;m++)
			cout<<a[m]<<" ";
	}
	else{
		int k=1;
        	//for all odd indexes swapping negative element with positive element
		while(k<n && i<n)
		{
			int temp=a[k];
			a[k]=a[i];
			a[i]=temp;
			k+=2;
			i++;
		}
		for(int m=0;m<n;m++)
			cout<<a[m]<<" ";
	}
}