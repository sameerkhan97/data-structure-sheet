/*Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings. */


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        int index = 0;
        string ans = "";
        while (true) 
        {
            if (index >= strs[0].size()) 
                break;
            char commonChar = strs[0][index];
            for (int i=1; i<strs.size(); ++i) 
            {
                if (strs[i][index] != commonChar || index >= strs[i].size())
                    return ans;
            }
            ans =ans+commonChar;
            index++;   
        }
        return ans;
    }
};