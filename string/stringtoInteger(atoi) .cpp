/*Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
The algorithm for myAtoi(string s) is as follows:
1.Read in and ignore any leading whitespace.
2.Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either.
  This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3.Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
4.Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0.
  Change the sign as necessary (from step 2).
5.If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. 
  Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
6.Return the integer as the final result.
Note:
Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits. */
 Example 1:
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42. */



class Solution {
public:
    int myAtoi(string s) {
        string temp = "";
        int sign = 1;
        long sum = 0;
        int n = s.length();
        int i = 0;
        while(s[i]==' ')
        {      
            i++;
            if(i==n-1)
            {
                return 0;
                break;
            }
        }
        if(s[i]=='-')
        {
            sign = -1;
            temp = s.substr(i+1,n-1-i);
        }
        else if(s[i]=='+')
            temp = s.substr(i+1,n-1-i);
        else
            temp = s.substr(i,n-i);
        
        n = temp.length();
        i = 0;
        while(i<n)
        {
            if((temp[i]-'0')>9|| temp[i]-'0'<0)
                return sumsign;
            else
            {
                sum = sum10 + (temp[i]-'0');
                if(sign == -1 && sum>pow(2,31))
                        return -1pow(2,31);
                else if(sign == 1 && sum>pow(2,31)-1)
                        return pow(2,31)-1;
            }
            i++;
        }
        return sumsign;
    }
};