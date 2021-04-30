/*There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array 
is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at 
pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1                                      */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //if given array size is 1 then return if the element found or not
        if(nums.size()==1)
            return (nums[0]==target)?0:-1;
    
        //pivotIndex to store location of pivot Element which is the peek or the array
        int pivotIndex;
        int i=1;
        //iterating till we find pivot element
        while(i<nums.size() && nums[i]>=nums[i-1])
        {
            i++;
        }
        //if pivotElement is found at last that means array is simply orted
        if(i==nums.size())
        {
            for(i=0;i<nums.size();i++)
            {
                if(nums[i]==target)
                    return i;
            }
            return -1;
        }
        //assingning pivotelement's location to 
        pivotIndex=i-1;
        if(nums[pivotIndex]==target)
            return pivotIndex;

        //searching element in left side of pivot element
        if(target<nums[pivotIndex] && target>=nums[0])
        {
            int left=0,right=pivotIndex-1;
            while(left<=right)
            {
                if(nums[left]==target)
                    return left;
                left++;
                if(nums[right]==target)
                    return right;
                right--;
            }
        }
        //searching element in right side of pivot element
        else
        {
            int left=pivotIndex+1,right=nums.size()-1;
            while(left<=right)
            {
                if(nums[left]==target)
                    return left;
                left++;
                if(nums[right]==target)
                    return right;
                right--;
            }
            
        }
        return -1;
    }
};