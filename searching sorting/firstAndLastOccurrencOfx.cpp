/*Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x 
in the given array.If the number x is not found in the array just return both index as -1.

Example 1:
Input: n=9, x=5, arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 

Example 2:
Input: n=9, x=7, arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 						*/


vector<int> find(int arr[], int n , int x )
{
    //initially storing -1
    vector<int> ans(2,-1);
    int c=0;
    for(int i=0;i<n;i++)
    {
        //for fisrt occurance of x insert index 
        if(arr[i]==x && c==0)
        {
            ans[0]=i;
            ans[1]=i;
            c++;
        }
        //for last occurance of x inserting index 
        else if(arr[i]==x)
            ans[1]=i;
    }
    return ans;
}
