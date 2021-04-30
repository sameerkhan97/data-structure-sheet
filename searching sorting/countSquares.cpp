/*Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, 
  you have to output the number of integers less than N in the sample space S.
Example 1:
Input : N = 9
Output: 2
Explanation: 1 and 4 are the only Perfect Squares less than 9. So, the Output is 2.

Example 2:
Input : N = 3
Output: 1
Explanation: 1 is the only Perfect Square less than 3. So, the Output is 1. */



//There are sqrt(n) Perfect Squares between 1 and n.
class Solution {
  public:
    int countSquares(int N) {
        return sqrt(N-1);
    }
};