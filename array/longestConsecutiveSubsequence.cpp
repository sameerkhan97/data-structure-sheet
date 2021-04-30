/*Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are 
consecutive integers, the consecutive numbers can be in any order.
Example 1:
Input: N = 7   a[] = {2,6,1,9,4,5,3}
Output:6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence. */


class Solution{
  public:
    
    int findLongestConseqSubseq(int arr[], int N)
    {
        set <int> hashSet;
        //copying all array element into set
        for(int num=0;num<N;num++)
            hashSet.insert(arr[num]);
        
        //longestStrek will stores length of maximum consequtive subarray    
        int longestStreak=0;
        for(int num=0;num<N;num++)
        {
            //if current num is starting of consequtive sequence 
            if(!hashSet.count(arr[num]-1))
            {
                int currentNum=arr[num];
                int currentStreak=1;
                //iterating untill consequtive elements are found in set
                while(hashSet.count(currentNum+1))
                {
                    currentNum++;
                    //incrementing currentStreak every time we found a consequtive number
                    currentStreak++;
                }
                //if length of current consequtive subarray is greater than previous then 
                //assign longestStreak to it
                longestStreak=max(currentStreak,longestStreak);
            }
        }
        return longestStreak;
    }
};