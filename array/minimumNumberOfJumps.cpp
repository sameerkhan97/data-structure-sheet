/* Q-Given an array of  integers where each element represents the max number of steps that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element. */
#include<bits/stdc++.h>
using namespace std;
// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    //c-count no of jumps
    int i=0,c=0;
  //i will jump untill last element and c will be counting no. of jumps
    while(i<n-1)
    {
        i=i+arr[i];
        c++;
    }
    return c;
}
int main()
{
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    return 0;
}
