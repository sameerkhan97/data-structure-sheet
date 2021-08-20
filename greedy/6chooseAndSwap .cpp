/* You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences 
   of the first character with the second character and replace all the occurences of the second character with the first character. Your aim 
   is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
Input: A = "ccad"
Output: "aacd"
Explanation: In ccad, we choose ‘a’ and ‘c’ and after doing the replacement operation once we get, aacd and this is the lexicographically
             smallest string possible. 

Example 2:
Input: A = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for ‘a’ and ‘b’ but that is not lexicographically smaller 
             than abba. So, the answer is abba. 
             */

class Solution{
public:
    string chooseandswap(string a){
        set<char> s;
        //inserting all char into set
        for(int i=0;i<a.size();i++) s.insert(a[i]);
        for(int i=0;i<a.size();i++){
            //erasing surrent element for set
            s.erase(a[i]);
            if(s.empty())  break;
            //set.begin() will give first and smallest char from set
            char ch1= *s.begin();
            //if current string char is greater than smallest char from set
            //then swapping both chars in string
            if(ch1<a[i]){
                char ch2=a[i];
                for(int j=0;j<a.size();j++){
                    if(a[j]==ch1)   a[j]=ch2;
                    else if(a[j]==ch2)   a[j]=ch1;
                }
                break;
            }
        }
        return a;
    }
    
};