/*Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets 
  with the sum smaller than the given sum value X.

Example 1:
Input: N = 6, X = 2 	arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Example 2:
Input: N = 5, X = 12 	arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5),(1, 3, 7) and (1, 4, 5).          */

class Solution{	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    long long count=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n-2;i++)
	    {
	        //taking 2 pointer 1 next to current array element
	        //other at last element
	        int j=i+1,k=n-1;
	        while(j<k)
	        {
	            //if the current sum of triplet is > sum then decrease last pointer
	            //it will point to smaller value bcoz array is sorted
	            if(arr[i]+arr[j]+arr[k]>=sum)
	                k--;
	            else if(arr[i]+arr[j]+arr[k]<sum)
	            {
	                //when we found that current triplet < sum then element between them will be
	                //also < sum hence incrementing count by no. of elements between them
	                count+=k-j;
	                j++;
	            }
	        }
	    }
	    return count;
	}
};
