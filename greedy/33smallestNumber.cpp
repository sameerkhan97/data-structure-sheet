/*The task is to find the smallest number with given sum of digits as S and number of digits as D.

Example 1:
Input:  S = 9   ,   D = 2
Output: 18
Explanation: 18 is the smallest number possible with sum = 9 and total digits = 2.
 
Example 2:
Input: S = 20   ,   D = 3
Output: 299
Explanation: 299 is the smallest number possible with sum = 20 and total digits = 3
*/

class Solution{   
public:
    string smallestNumber(int s, int d){
        if(d*9<s)   return "-1";
        string ans;
        for(int i=d-1;i>=0;i--){
            if(s>9){
                ans="9"+ans;
                s=s-9;
            } 
            else{
                if(i==0)
                    ans=to_string(s)+ans;
                else{
                    ans=to_string(s-1)+ans;
                    s=s-1;
                    i--;
                    while(i>0){
                        ans="0"+ans;
                        i--;
                    }
                    ans="1"+ans;
                    break;
                }
            }
        }
        return ans;
    }
};