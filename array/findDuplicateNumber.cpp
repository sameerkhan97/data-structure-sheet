/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number. */
//NORMAL APROACH :
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i,j;
        //traversing array
        for(i=0;i<nums.size();i++)
        {
            //comparing each element with its forward's element and if found same then break; 
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                    break;
            }
            //return the duplicate element
            if(j<nums.size())
                return nums[i];
        }
        return -1;
    }
};

//OPTIMAL APROACH : 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //taking two variables initially pointing 1st element
        int slow=nums[0],fast=nums[0];
        do{
            //increasing slow by1 and fast by 2 untill slow and fast overlapp
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        //after overlap leave slow as it is and point fast to 1st element again
        fast=nums[0];
        //now increase both slow and fast by 1 untill overlap
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        //element on which slow and fast overlap will be duplicate element
        return slow;
    }
};

