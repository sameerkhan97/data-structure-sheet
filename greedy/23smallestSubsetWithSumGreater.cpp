/*Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater 
than the sum of rest of the elements of the array.

Examples : 
Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of this subset is greater than all other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not enough. We can pick elements with values 1, 2 or 2, 2. In any case, the minimum count is 2.
*/

#include<iostream> 
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
sort(arr,arr+n);
int s=0;
//getting sum of all array element
for(int i=0;i<n;i++)
    s=s+arr[i];

int s2=0;
int ansCount=0;

//traversing array in reverse i.e from largest element
for(int i=n-1;i>=0;i--){
    s=s-arr[i];
    s2=s2+arr[i];
    //count number of elements
    ansCount++;
    //if the addition of current element exceed the sum of array elements then its minimum subset 
    if(s2>s)
        break;
}
cout<<"\n"<<ansCount;
