/*Given a string s, return the longest palindromic substring in s.
Example 1: Input: s = "babad" ,Output: "bab"
Note: "aba" is also a valid answer. */



class Solution 
{
private:
    int getPalindromLength(string& s, int left, int right)
    {
        // Move left and right bounds only while they within string size and characters of both are equal
        while( left >= 0 && right < s.length() && s[left] == s[right] )
        {
            --left;
            ++right;
        }
        // Return length between left and right bounds
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) 
    {   
        // In case string contain only one character - this is a Palindrome
        if(s.length() == 1) { return s; }
        
        // Left and right bounds - between them Palindrom located
        int leftIndex, rightIndex;
        leftIndex = rightIndex = 0;
        
        // Imagine that each character is a middle of Palindrome and checking neighbors to find max length
        for(int i = 0; i < s.length(); ++i )
        {
            // Count length for current index
            int currentLength = getPalindromLength(s, i, i);
            // Count length for current-next index - required for pair characters( example: "aa", "baa", "baac" )
            int pairLength = getPalindromLength(s, i, i+1);
            // Take current max length between previous two
            int maxLength = currentLength >= pairLength ? currentLength : pairLength;
            // Only if maxLength more than previous found length - update left and right bounds
            if ( maxLength > rightIndex - leftIndex )
            {
                // Left bound - from current index(because it's middle of Palindrome) deduct (found length - 1) / 2
                leftIndex = i - (maxLength - 1) / 2;
                // Right bound - to current index(because it's middle of Palindrome) add found length / 2
                rightIndex = i + maxLength / 2;
         
            }
        }
        // Return Palindrome. substr first parameter indicates from which position starts, second parameter indicates how many characters take
        return s.substr(leftIndex, rightIndex - leftIndex + 1);
    }
};