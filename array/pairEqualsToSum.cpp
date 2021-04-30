/*Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:
Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1. */


//Brute-Force O(n^2)
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int c=0,temp[n];
        for(int i=0;i<n;i++)
            temp[i]=arr[i];
        for(int i=0;i<n;i++)
        {
            if(arr[i])
        }
        return c;
    }
};

//Optimal O(n) 
class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
        //map to store frequency of current element
	unordered_map<int,int> m;
	int x,c=0;
        for(int i=0;i<n;i++)
        {
            x=k-a[i];
            if(m[x]==0)
            {
                m[a[i]]++;
            }
            else
            {
                c+=m[x];
                m[a[i]]++;
            }
        }
        return c;
    }
};