// Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        long nn=n;
        double ans=1;
        if(nn<0)
            nn=-1*nn;
        while(nn>0)
        {
            if(nn%2==0)
            {  
                x=x*x;
                nn=nn/2;
            }
            else
            {
                ans=ans*x;
                nn--;
            }
        }
        if(n<0)
            ans=(double)(1.0)/(double)(ans);
        
        return ans;
    }
};