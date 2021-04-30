class Solution{
	public :
	int maxProfit(vector<int>& a)
	{
		int n=a.size();
		//Create profit array dp and initialize it as 0
        int dp[n]={0};
        //Get the maximum profit with only one transaction allowed. After this loop,profit[i] contains maximum profit from price[i..n-1]
        // using at most one trans
		int ma=a[n-1];
		for(int i=n-2;i>=0;i--)
		{
            // ma has maximum of price[i..n-1]
			if(a[i]>ma)
				ma=a[i];
            // we can get profit[i] by taking maximum of: a) previous maximum, i.e., profit[i+1] b) profit by buying at price[i] and selling at    max_price
			dp[i]=max(dp[i+1],ma-a[i]);
		}
        // Get the maximum profit with two transactions allowed After this loop, profit[n-1] contains the result 
        int mi=a[0];
		for(int i=1;i<n;i++)
		{
            // mi has minimum price in price[0..i]
			if(a[i]<mi)
				mi=a[i];
            // Maximum profit is maximum of a) previous maximum, i.e., profit[i-1] b) (Buy, Sell) at (min_price, price[i]) and add
            // profit of other trans. stored in profit[i]
			dp[i]=max(dp[i-1],dp[i]+(a[i]-mi));
		}
		return dp[n-1];
	}