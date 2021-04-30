/*Given an array of n positive integers and a number k. Find the minimum number of swaps required 
to bring all the numbers less than or equal to k together.

Example 1:
â€‹Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
Explanation: To bring elements 2, 1, 3 together, swap element '5' with '3' such that final array will be- arr[] = {2, 1, 3, 6, 5}

Example 2:
Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
Output :  2  */


//using sliding window technique
int minSwap(int *arr, int n, int k) {
    //good will store the no of elements <= k which will be length of window
    //bad will count numbers > k
    int good=0,bad=0;
    for(int i=0;i<n;i++)
    {
       if(arr[i]<=k)
            good++;
    }
    //in the first window counting elements greater than k and storing in bad
    for(int i=0;i<good;i++)
    {
        if(arr[i]>k)
            bad++;
    }
    //minSwap will store minimum swap and hence it is initialized with large integer
    int minSwap=10000;
    int i=0,j=good-1;
    while(j<n)
    {
        //storing minimum between current greater element and previous element
        minSwap=min(minSwap,bad);
        //extending window from right side
        j++;
        //if newest element in window is > k then increment bad;
        if(arr[j]>k && j<n)
            bad++;
        //is oldest element in window is < k then decrement bad
        if(arr[i]>k)
            bad--;
        //extending window from left side
        i++;
    }
    return minSwap;
}

