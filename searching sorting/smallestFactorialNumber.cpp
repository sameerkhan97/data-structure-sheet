/*Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.
Example 1:
Input: n = 1 , Output: 5
Explanation : 5! = 120 which has at least 1 trailing 0.

Example 2:
Input: n = 6 , Output: 25
Explanation : 25! has at least 6 trailing 0.           */


class Solution
{
    public:
        //check if mid element has n zero or not
        //will use formulla : 
        // no. of zero=(x/5)+(x/25)+(x/125)....until denominator < than numeraator(x)
        
        bool check(int mid,int n)
        {
            int temp=mid,f=5,count=0;
            //count to store occurance of zero
            while(f<=temp)
            {
                count+=temp/f;
                f=f*5;
            }
            //if count has > 0s than n then  return true
            return (count>=n);
        }
        
        int findNum(int n)
        {
            //basic case
            if(n==1)
                return 5;
                
            //high will store max value attain by n;
            int low=0,high=5*n;
            while(low<high)
            {
                int mid=(low+high)/2;
                //check if the mid element has at least n zero
                if(check(mid,n))
                {   //if mid has n zero then we will search in smaller elements than mid
                    //becoz we need to find the minmum
                    high=mid;
                }
                else
                {
                    //if mid dont have n zero then we will search in greater elements than mid
                    low=mid+1;
                }
            }
            return low;
        }
};