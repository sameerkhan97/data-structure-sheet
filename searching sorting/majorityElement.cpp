/*Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that 
 appears more than N/2 times in the array.
 
Example 1:
Input: N = 3     A[] = {1,2,3} 
Output: -1
Explanation: Since, each element in {1,2,3} appears only once so there is no majority element.
Example 2:
Input: N = 5   A[] = {3,1,3,3,2} 
Output: 3
Explanation: Since, 3 is present more than N/2 times, so it is the majority element.   */


int majorityElement(int a[], int size)
{
    int max=0;
    //find maximum element of array 
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    //initilize an array of size maximum to store frequency of all elements
    int freq[max+1];
    //initializing array with 0
    for(int i=0;i<=max;i++)
        freq[i]=0;
    
    //inserting occurance of eaach element and check if it is > size/2 or not
    for(int i=0;i<size;i++)
    {
        freq[a[i]]++;
        if(freq[a[i]]>(size/2))
            return a[i];
    }
    return -1;
}