/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Follow-up: Could you solve the problem in linear time and in O(1) space?
Example 1: Input: nums = [1,2]  Output: [1,2]   */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> s;
        int el1=-1,el2=-1,c1=0,c2=0;
        for(int num : nums)
        {
            if(num==el1)
                c1++;
            else if(num==el2)
                c2++;
            else if(c1==0)
            {
                c1++;
                el1=num;
            }
            else if(c2==0)
            {
                c2++;
                el2=num;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(int num : nums)
        {
            if(num==el1)
                c1++;
            else if(num==el2)
                c2++;
        }
        if(c1>nums.size()/3)
            s.push_back(el1);
        if(c2>nums.size()/3)
            s.push_back(el2);
        return s;
    }
};