/*Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).
Example 1:
Input: A[] = {1, 4, 45, 6, 0, 19}  x  =  51
Output: 3
Explanation: Minimum length subarray is {4, 45, 6}
Example 2:
Input: A[] = {1, 10, 5, 2, 7} x  = 9
Output: 1
Explanation: Minimum length subarray is {10}  */


class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        //minLength contain minimum length of subArray
        int minLength=n+1,sum=0;
        int i=0,j=0;
        while(i<n)
        {
            //i will iterate untill we get sum>x 
            while(sum<=x && i<n)
            {
                sum+=arr[i++];
            }
            //after getting sum start substracting from 1st element of sub array
            while(sum>x && j<n)
            {
                //after substracting if value of sum is still greater than x
                //then update the new subarray with sum>x
                
                if(i-j<minLength)
                    minLength=i-j;
                
                //substracting from 1st elements of subarray
                sum-=arr[j++];
            }
        }
        return minLength;
    }
};