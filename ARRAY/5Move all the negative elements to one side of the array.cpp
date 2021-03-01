// Q-An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
//Note: Order of elements is not important here.
#include <iostream>
using namespace std;

int main() {
	int a[]={1,5,4,-9,-1,-21,-58,1},i,j;
	int n=sizeof(a)/sizeof(a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j]<0)
				{
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
					i++;
				}
			}
		}
	}
	for(i=0;i<n;i++)	
		cout<<a[i]<<" ";
	return 0;
}