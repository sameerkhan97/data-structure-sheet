/*Given an array a[ ] of N elements. Consider array as a circular array i.e. element after an is a1. The task is to find maximum sum of the
 absolute difference between consecutive elements with rearrangement of array elements allowed i.e. after any rearrangement of array elements 
 find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|.

Example 1:
Input: N = 4    ,   a[] = {4, 2, 1, 8}
Output: 18
Explanation: Rearrangement done is {1, 8, 2, 4}. Sum of absolute difference between consecutive elements after rearrangement = 
|1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18.

Example 2:
Input: N = 2    ,   a[] = {10, 12}
Output: 4
*/

bool comp(int a,int b){
    if(a>b) return true;
    return false;
}

long long int maxSum(int arr[], int n)
{
    long long int sum = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n/2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }
    return sum;
}