/*Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
Example 1:
Input:
5
4 2 -3 1 6
Output: 
Yes  */ 







class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    
    //we will count prefix sum for each element and store it in map
    //return true if prefix sum of any two elements matches or element is zero 
    bool subArrayExists(int a[], int n)
    {
        //count prefix sum of each element in sum
        int sum=a[0];
        unordered_map<int,int> m;
        //marking prefix sum of 1st element
        m[sum]=1;
        for(int i=1;i<n;i++)
        {
            sum=sum+a[i];
            //checking if current prerfix sum alreadsy marked in map or not
            if(sum==0 or m[sum] or a[i]==0)
                return true;
            //if prefix sum isnt matched then mark sum in map as 1
            m[sum]=1;
        }
        return false;
    }
};