//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        int sum=0,max=arr[0];
        //ADDING ELEMENT I WITH I+1 BUT IF SUM<0 THEN LEAVE I AND ITERATE FORWARD
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>max)
                max=sum;
            if(sum<0)
                sum=0;
        }
        return max;     
    }
};
int main()
{
        int n;   
        cin>>n; //input size of array
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of arraY
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
}
