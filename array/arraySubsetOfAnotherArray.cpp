/* Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. 
Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
Example 1:
Input: a1[] = {11, 1, 13, 21, 3, 7}    a2[] = {11, 3, 7, 1}
Output: Yes
Explanation:a2[] is a subset of a1[]
Example 2:
Input: a1[] = {1, 2, 3, 4, 5, 6}    a2[] = {1, 2, 4}
Output: Yes
Explanation:a2[] is a subset of a1[]
Example 3:
Input:a1[] = {10, 5, 2, 23, 19}     a2[] = {19, 5, 3}
Output: No
Explanation: a2[] is not a subset of a1[] */


string isSubset(int a1[], int a2[], int n, int m) {
    int max=a1[0];
    //finding maximum element in a1
    for(int i=0;i<n;i++)
    {
        if(a1[i]>max)
            max=a1[i];
    }
    //creating temp-array to store occcurance of elements of a1
    int temp[max]={0};
    for(int i=0;i<n;i++)
    {
        temp[a1[i]]++;
    }
    //cross checking wheter elements of a2 occuired in a1 
    for(int j=0;j<m;j++)
    {
        if(temp[a2[j]]==0)
            return "No";
    }
    return "Yes";
}
