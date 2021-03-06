/* Given an unsorted array of integers nums, return the 
length of the longest consecutive elements sequence.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9 */
//Brute-Force Approach: 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int c=1,max=1;
        if(nums.empty())
            return 0;
            
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            c=1;
            //cmparing element at i with its next elements and counting if in sequence
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]+1==nums[j+1])
                    c++;
                else 
                    break;
            }
            if(c>max)
                max=c;           
        }
        return max;
    }
};
//Optimal Approach using Set Data Structure :
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       //heashSet will store all element of array
        set<int> hashSet;
        for(int num : nums)
            hashSet.insert(num);
        
        int longestStreak=0;
        for(int num : nums)
        {
            //comparing each element 1 by one
            //if (current element-1) is not present in hashset then move ahead
            if(!hashSet.count(num-1))
            {
                //take current Element as currentNum and its currentStreak as 1
                int currentNum=num;
                int currentStreak=1;
                //if sequenced elements of current element is present then increas element and streak
                while(hashSet.count(currentNum+1))
                {
                    currentNum++;
                    currentStreak++;
                }
                //if current element's streak is bigger then replace it will longestStreak
                longestStreak=max(longestStreak,currentStreak);
            }
        }
        return longestStreak;
    }
};
