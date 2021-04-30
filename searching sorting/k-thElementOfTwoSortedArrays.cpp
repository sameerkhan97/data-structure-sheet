/*Given two sorted arrays arr1 and arr2 of size M and N respectively and an element K. The task is to find the element 
   that would be at the k’th position of the final sorted array.
 
Example 1:
Input: arr1[] = {2, 3, 6, 7, 9} , arr2[] = {1, 4, 8, 10} , k = 5
Output: 6
Explanation:The final sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10
            The 5th element of this array is 6.

Example 2:
Input: arr1[] = {100, 112, 256, 349, 770} , arr2[] = {72, 86, 113, 119, 265, 445, 892} , k = 7
Output:256
Explanation:Final sorted array is - 72, 86, 100, 112,113, 119, 256, 265, 349, 445, 770, 892
            7th element of this array is 256.        */




//brute force : TC-O(N) , SC-O(N)
class Solution{
    public:

    //inserting both array in a vector in 1 by 1 and sort the vector then return k-1th index element
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(arr1[i]);
        for(int i=0;i<m;i++)
            ans.push_back(arr2[i]);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};


//Optimal : TC-O(N) , SC-O(1)
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //i-iterate first array,j-iterate 2nd array , x-count no of elements passed
        int i=0,j=0,x=0;
        while(i<n && j<m)
        {
            //inserting smaller element
            if(arr1[i]<arr2[j])
            {
                x++;
                //if current inserted element is kth element then return it
                if(x==k)
                    return arr1[i];
                //iterate to next element of array
                i++;
            }
            else
            {
                x++;
                if(x==k)
                    return arr2[j];
                j++;
            }
        }
        //when array 2 is ended and array 1 is remaining then checking for kth element in array 1
        while(i<n)
        {
            x++;
            if(x==k)
                return arr1[i];
            i++;
        }
        //when array 1 is ended and array 2 is remaining then checking for kth element in array 2
        while(j<m)
        {
            x++;
            if(x==k)
                return arr2[j];
            j++;
        }
    }
};