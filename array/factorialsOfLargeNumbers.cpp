/*Given an integer N, find its factorial.
Example 1:
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Example 2:
Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800    */





class Solution {
public:
    vector<int> factorial(int N)
    {
        //vector fact will store the digits after each multiplication during factorial
        vector<int> fact;
        fact.push_back(1);
        //multiplying from 2 upto N 
        for(int i=2;i<=N;i++)
        {
            multiply(fact,i);
        }
        //fact will contin digit of finl result in reverse order so we need to reverse it agaian
        reverse(fact.begin(),fact.end());
        return fact;
    }
    void multiply(vector<int>& fact,int n)
    {
        //initially carry will be zero
        int carry =0;
        for(int i=0;i<fact.size();i++)
        {
            //number will be multiplied with each digit of current factorial
            int num=n*fact[i]+carry;
            //last digit of resultant will be stored in vector and 
            //rest will be passed as carry 
            fact[i]=num%10;
            carry=num/10;
        }
        //if all digits are multiplied and carry is left
        //then add each digit of carry into vector
        while(carry)
        {
            fact.push_back(carry%10);
            carry/=10;
        }
    }
};
