/*Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. 
If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
Notice: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc".
Example 1: Input: a = "abcd", b = "cdabcdab" , Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2: Input: a = "a", b = "aa" ,Output: 2 */

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        //Pattern is b
        //text is a 
        //construct the lps for b
        int nA = a.size() , nB = b.size() , i , j;
        
        vector<int> lps(nB,0) ;
        
        for (i=1 ; i<nB ; i++) 
        {
            j=lps[i-1] ;
            while (j>0 && b[j]!=b[i])
                j = lps[j-1] ;
            if (b[i]!=b[j])
                lps[i] = 0;
            else 
                lps[i]=j+1 ;
        }
        //Actual KMP
        int total_len = nA*((nB/nA)+2) ;
        i=0 ; j=0 ;
        while (i<total_len) 
        {
            //finding first mismatch
            while (j<nB && b[j] == a[i%nA]) 
            { 
                //i%nA coz we aren't actually concatenating the strings 
                i++ ; j++ ;
            }
            //No mismatch
            if (j == nB)
                return ceil((float)i/nA) ; //the no.of times A has been repeated
            
            //Mismatch
            if (j==0)
                i++ ;
            else 
                j = lps[j-1] ;
        }
        return -1 ;
    }
};