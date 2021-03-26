/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II. 
Example 1:
Input: s = "III"
Output: 3 */



class Solution {
public:
    int romanToInt(string s) {
        int num =0;
        for(int i=0;i<s.length();i++)
        {   if(s[i] == 'I')
                num+=1;
             else if(s[i] == 'X')
             {    if(i!=0 and s[i-1] == 'I')
                     num = (num-2) + 10;
                  else
                    num+=10;
             }
             else if(s[i] == 'V')
             {   if(i!=0 and s[i-1] == 'I')
                     num = (num-2) + 5;
                 else
                     num +=5;
             }
             else if(s[i] == 'L')
             {
                 if(i!=0 and s[i-1] == 'X')
                     num = (num-20) + 50;
                 else
                     num+=50;
             }  
              else if(s[i] == 'C')
             {
                 if(i!=0 and s[i-1] == 'X')
                     num = (num-20) + 100;
                 else
                     num+=100;
             }  
             else if(s[i] == 'D')
             {
                 if(i!=0 and s[i-1] == 'C')
                     num = (num-200) + 500;
                 else
                     num+=500;
             }  
             else if(s[i] == 'M')
             {
                 if(i!=0 and s[i-1] == 'C')
                     num = (num-200) + 1000;
                 else
                     num+=1000;
             }  
        }
        
        return num;
    }
};