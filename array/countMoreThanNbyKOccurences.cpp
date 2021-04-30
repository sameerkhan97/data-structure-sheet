/*Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.
Example 1:
Input: N = 8   arr[] = {3,1,2,2,1,2,3,3}   k = 4
Output: 2
Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times.
Example 2:
Input: N = 4   arr[] = {2,3,3,2}    k = 3 
Output: 2
Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.  */



class Solution{
  public:
    int countOccurence(int arr[], int n, int k) {
        //getting maximum element of the array
        int max=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }
        //incrementing max by one because new array start with 0
        max++;
        //initializing an array of max size which will stores occurance of each element
        int temp[max]={0};
        int c=0;
        //storing occurance of each element
        for(int i=0;i<n;i++)
        {
            temp[arr[i]]++;
        }
        //now searchinh which elements occured more than n/k Times
        for(int i=0;i<max;i++)
        {
            if(temp[i]>(n/k))
                c++;
        }
        return c;
    }
};