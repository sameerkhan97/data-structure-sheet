/*Given an array a, we have to find maximum product possible with the subset of elements present in the array. The maximum product can be
  single element also.

Examples: 
Input: a[] = { -1, -1, -2, 4, 3 }
Output: 24
Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

Input: a[] = { -1, 0 }
Output: 0
Explanation: 0(single element) is maximum product possible
 
Input: a[] = { 0, 0, 0 }
Output: 0
*/

//Approach :
//1] If there are even number of negative numbers and no zeros, result is simply product of all
//2] If there are odd number of negative numbers and no zeros, result is product of all except the negative integer with the least absolute value.
//3] If there are zeros, result is product of all except these zeros with one exceptional case. The exceptional case is when there is one negative
//   number and all other elements are 0. In this case, result is 0.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	// Find count of negative numbers, count of zeros, negative number with least absolute value
    // and product of non-zero numbers
	int zeroCount=0,negCount=0;
	int maxNeg=INT_MIN;
	int prod=1;
	for(int i=0;i<n;i++){
		// If number is 0, we don't multiply it with product.
		if(a[i]==0){
			zeroCount++;
			continue;
		}
		//Count negatives and keep track of negative number with least absolute value
		else if(a[i]<0){
			negCount++;
			maxNeg=max(maxNeg,a[i]);
		}
		prod=prod*a[i];
	}
	// If there are all zeros
	if(zeroCount==n)
		cout<<"0 ";
	// Exceptional case: There is only negative and all other are zeros
	else if(negCount==1 && negCount+zeroCount==n)
		cout<<"0 ";
	// If there are odd number of negative numbers
	else if(negCount%2==1){
		result is product of
        // all non-zeros divided by negative number with least absolute value
		prod=prod/maxNeg;
	}
	
	cout<<prod;	
}