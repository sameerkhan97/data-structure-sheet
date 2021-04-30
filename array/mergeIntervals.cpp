/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping
 intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]     Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
Input: intervals = [[1,4],[4,5]]    Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping. */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        if(interval.size()==1)
            return interval;
        
        sort(interval.begin(),interval.end());
        
        vector<vector<int>> res;
        // start & end - to keep track of start & end of current interval
        int start =interval[0][0],end=interval[0][1];
        for(int i=1;i<interval.size();i++)
        {
            if(interval[i][0]<=end)
            {
                 // current interval is overlapping
                // extend the current interval
                end=max(end,interval[i][1]);
            }
            else{
                // no overlapp
                // push the previous interval in answer
                res.push_back({start,end});
                // start a new interval
                start=interval[i][0];
                end=interval[i][1];
            }
        }
        // push the last interval
        res.push_back({start, end});
        
        return res;
        
        
    }
};