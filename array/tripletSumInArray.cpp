/*Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
Example 1:
Input: n = 6, X = 13   arr[] = [1 4 45 6 10 8]
Output: 1
Explanation: The triplet {1, 4, 8} in the array sums up to 13.
Example 2:
Input: n = 5, X = 10   arr[] = [1 2 4 3 6]
Output: 1
Explanation: The triplet {1, 3, 6} in the array sums up to 10. */


bool find3Numbers(int a[], int n, int X)
{
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        //for each element selecting 2 pointer pointing next and last element
        int l=i+1;
        int r=n-1;
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==X)
                return 1;
            //if sum of 3 elements is less then decrement then increment l pointer  
            //after incrementing r will point to larger value
            else if(a[i]+a[l]+a[r]<X)
                l++;
            //if sum of 3 elements is more then decrement the r pointer
            //after deccrementing it will point to smaller value
            else if(a[i]+a[l]+a[r]>X)
                r--;
        }
    }
    return 0;
}