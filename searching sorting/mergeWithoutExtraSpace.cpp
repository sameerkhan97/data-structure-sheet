/*Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one
  sorted array in non-decreasing order without using any extra space.

Example 1:
Input: N = 4, M = 5 , arr1[] = {1, 3, 5, 7} , arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any extra space, modify the given arrays to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Example 2:
Input: N = 2, M = 3 , arr1[] = {10, 12} , arr2[] = {5, 18, 20}
Output: 5 10 12 18 20
Explanation: Since you can't use any extra space, modify the given arrays to form 
arr1[] = {5, 10}
arr2[] = {12, 18, 20}                                                            */


class Solution{
public:
	int nextGap(int gap)
	{
	    if(gap<=1)
	        return 0;
	    return (gap/2)+(gap%2);
	}
	void swap(int &a,int &b)
	{
	    int t=a;
	    a=b;
	    b=t;
	}
	void merge(int arr1[], int arr2[], int n, int m) {
	    //gap to use as index and every element will be compared with its gap element
        int gap=n+m,j,i;
        for(gap=nextGap(gap);gap>0;gap=nextGap(gap))
	    {
            //in first array iterating and comparing elements with gap untill array end.
	        for(i=0;i+gap<n;i++)
	        {
	            if(arr1[i]>arr1[i+gap])
	                swap(arr1[i],arr1[i+gap]);
	        }
            //now i will keep pointing to 1st array and j will point to second arrays corresponding gap element
	        for(j=gap>n?gap-n:0;i<n && j<m;i++,j++)
	        {
	            if(arr1[i]>arr2[j])
	                swap(arr1[i],arr2[j]);
	        }
            //after comparing all elements of first array 
            //if the second array is left
	        if(j<m)
	        {
                //comparing remaining element of second array
 	            for(j=0;j+gap<m;j++)
	            {
	                if(arr2[j]>arr2[j+gap])
	                    swap(arr2[j],arr2[j+gap]);
	            }
	        }
	    }
	}
};