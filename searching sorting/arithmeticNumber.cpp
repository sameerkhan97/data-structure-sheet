/*Given three integers  'a' denoting the first term of an arithmetic sequence ,'c' denoting the common difference of an arithmetic sequence 
  and an integer 'b'. you need to tell whether 'b' exists in the arithmetic sequence or not.

Example 1:
Input: A = 1, B = 3, C = 2
Output: 1
Explaination: 3 is the second term of the sequence starting with 1 and having a common difference 2.

Example 2:
Input: A = 1, B = 2, C = 3
Output: 0
Explaination: 2 is not present in the sequence.     */



class Solution{
public:
    int inSequence(int a, int b, int c){
        //imp formulla :
        // n=(b-a)/c + 1; where n-is no of terms and always >=1
        
        
        //if the difference is 0  that means we dont have any arithmatic sequence except a
        //hence if ==b then we find b else we return false
        if(c==0)
        {
            if(a==b)
                return 1;
            else
                return  0;
        }
        else
        {
            //if (b-a)/c is less than zero then it will make no of terms s 0 or negtive
            //which is practically not possible hence return false
            if((b-a)/c<0)
                return 0;
            else
            {
                //if (b-a)/c gives a proper number then we can return true 
                if((b-a)%c==0)
                    return 1;
                else
                    return 0;
            }
        }
    }
};
