/*Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Example 1:
Input: n = 5   A[] = {1, 2, 3, 3, 4}   [a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be 1.
Example 2:
Input: n = 3    A[] = {1, 2, 3}    [a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement is: {1, 2, 3}. If you return a valid arrangement, output will be 1. */


class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        //l-will move all value smaller than a to les=ft side 
        //h-will move values greater than b to right side
        int l=0,h=arr.size()-1;
        for(int i=0;i<=h;)
        {
            //if current value is less than a then swap it to left of l
            if(arr[i]<a)
            {
                swap(arr[i],arr[l]);
                l++;
                i++;
            }
            //if current value is greater than b then swap it to right of h 
            else if(arr[i]>b)
            {
                swap(arr[i],arr[h]);
                h--;
            }
            //if the value is between a&b then dont do anything just move next Element
            else
                i++;
        }
    }
};