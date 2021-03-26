/*Given an input string s, reverse the order of the words.Return a string of the words in reverse order concatenated by a single space. 
The returned string should only have a single space separating the words. Do not include any extra spaces.
Example 1:
Input: s = "the sky is blue" Output: "blue is sky the"

Example 2:
Input: s = "  hello world  " Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
*/

class Solution {
public:
    string reverseWords(string s)
    {
        string res="";
        
        //stack to store words of a String
        stack<string> stc;
        for(int i=0;i<s.length();i++)
        {
            //if current word is " " then move untill an alphabet
            while(isspace(s[i]))
                i++;
            
            string temp="";
            //copying a word in string temp
            while(i<s.length() && isalnum(s[i]))
            {
                temp.push_back(s[i]);
                i++;
            }
            
            //inserting word in string temp into stack stc
            if(temp.size()>0)
                stc.push(temp);            
        }
        
        
        //inserting all words from stack stc into res String 
        //this will be automatically give reverse order String because
        //stack obey FILO structure
        while(!stc.empty())
        {
            res=res+stc.top();
            stc.pop();
            if(!stc.empty())
                res=res+" ";
        }
        return res;
    }
};