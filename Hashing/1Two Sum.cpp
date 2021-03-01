/* Given an array of integers nums and an integer target,
 return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1] , Because nums[0] + nums[1] == 9, we return [0, 1]. */
//Brute-Force approach : 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> p;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    p.push_back(i);
                    p.push_back(j);
                    break;
                }
            }
        }
        return p;
    }
};
//Optimal Approach : Using HashSet
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end())
            {
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};