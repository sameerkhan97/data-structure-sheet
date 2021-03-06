/* iven an array nums of n integers and an integer target, are there elements a, b, c, and d in nums
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Notice that the solution set must not contain duplicate quadruplets.
Example 1: Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]   */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //res will store quadraplets
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            //i-pointing to first element and j-pointing to next element
            for(int j=i+1;j<nums.size();j++)
            {
                //sum of i,j will be deducted from target to get a new target
                int target2=target-nums[i]-nums[j];
                int front=j+1;          //front pointing to next element of j
                int back=nums.size()-1; //back pointing to last element of array 
                //iterating array with front and back
                while(back>front)
                {
                    //searching for elemenet where Target2=nums[front]+nums[back]
                    if(nums[front]+nums[back]>target2)
                        back--;
                    else if(nums[front]+nums[back]<target2)
                        front++;
                    //found front and back such that target2=front +back
                    //now creating array of i,j,front,back to add as quadralets
                    else
                    {
                        vector<int> quadralets(4,0);
                        quadralets[0]=i;
                        quadralets[1]=j;
                        quadralets[2]=front;
                        quadralets[3]=back;
                        res.push_back(quadralets);
                        
                        //processing duplicate for number 3
                        while(front<back && nums[front]==quadralets[2])
                            front++;
                        //processing duplicate for number 4
                        while(front<back && nums[back]==quadralets[3])
                             back--;
                    }
                } 
                //processing for number 2
                while(j+1<nums.size() && nums[j+1]==nums[j])
                    j++;
            }
             //processing for number 1
                while(i+1<nums.size() && nums[i+1]==nums[i])
                    i++;
               
        }
        return res;
    }
};
