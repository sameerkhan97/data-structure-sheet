/*Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

Example 1:
Input: A = 978, B = 518, C = 300
Output: 518

Example 2:
Input: A = 162, B = 934, C = 200
Output: 200     */


//Brute-Force :
class Solution{
  public:
    int middle(int A, int B, int C){
        if((A>B && A<C) || (A<B && A>C))
            return A;
        else if((B>A && B<C) || (B<A && B>C))
            return B;
        else if((C>A && C<B) || (C<A && C>B))
            return C;
    }
};

//Optimal :
class Solution{
  public:
    int middle(int A, int B, int C){
        if(A>B)
            return (B>C)?B:max(A,C);
        return (B<C)?B:max(A,C);
    }
};