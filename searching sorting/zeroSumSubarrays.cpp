/*You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:
Input: n =  6       arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].

Example 2:
Input: n = 10      arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4],[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]      */

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> nums, int n ) {
        int sum = 0,count= 0;
        //using map to store the prefix sum which has appeared already.
        unordered_map<int,int> u;
        for(int i=0; i<n ;i++)
        {
            //storing prefix sum.
            sum += nums[i];
            //if prefix sum is zero that means we get a subarray with sum=0.
            if(sum == 0){
                //incrementing the counter.
                count++;
            }
            //if prefix sum is already present in map then it is repeated 
            //which means there is a subarray whose summation is 0.
            if(u.count(sum)){
                //we add the value at prefix sum in map to counter.
                count += u[sum];
            }
            //incrementing the count of prefix sum obtained in map.
            u[sum]++;
        }
        return  count;
    }
};