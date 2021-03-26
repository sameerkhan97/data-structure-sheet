/* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
Example 1: Input: haystack = "hello", needle = "ll"  ,Output: 2
Example 2: Input: haystack = "aaaaa", needle = "bba" ,Output: -1 */

int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        
        int i=0,j=0, s1=haystack.size(),s2=needle.size(),ind=-1;
        if(s2>s1) return ind;
        
        while(i<s1)
        {
            if(j == s2) //Search Complete
                break; 
            
            if(haystack[i] == needle[j])
            {
                // Start Matching the needle
                if(ind == -1) 
                    ind = i;
                ++j;
            }
            else if(ind != -1)
            {
                // Match failed. Reset search index to the first matched index. 
                // It will be incremented at end
                i = ind;
                j = 0;
                ind = -1;
            }
            ++i;
        }
        if( j != s2) // Complete match didn't occur
            ind=-1; 
        return ind;
        
    }
};