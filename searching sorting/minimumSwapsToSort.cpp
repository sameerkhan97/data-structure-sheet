/*Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
Example 1:
Input:nums = {2, 8, 5, 4}
Output: 1
Explaination: swap 8 with 4.

Example 2:
Input: nums = {10, 19, 6, 3, 5}
Output: 2
Explaination: swap 10 with 3 and swap 19 with 5.  */

class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    //we will store value in (value,index) pair
	    vector<pair<int,int>> v(nums.size());
	    for(int i=0;i<nums.size();i++)
	        v[i]={nums[i],i};
	   
	    //sort the pair vector
	    sort(v.begin(),v.end());
	    
	    int count=0;
	    //now we will try to convert the sorted array into original unsorted array
	    
	    //we will traverse through sorted pair vector 
	    for(int i=0;i<nums.size();i++)
	    {
	        //if the vector index is different from original array index
	        //then increment count and swap with the element having original index 
	        if(i!=v[i].second)
	        {
	            count++;
	            swap(v[i],v[v[i].second]);
	            //decrementing i because the swapped element must also be checked
	            i--;
	        }
	    }
	    return count;
	}
};