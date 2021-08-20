/*In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the
 stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of 
 money initially, find out the maximum number of stocks a customer can buy. 
For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

Examples: 
Input : price[] = { 10, 7, 19 } , k = 45.
Output : 4
A customer purchases 1 stock on day 1,  2 stocks on day 2 and 1 stock on day 3 for 10,   7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 } , k = 100.
Output : 6
*/

#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[]){
	vector<pair<int,int>> v;
	//inserting stock price and day pair in vector v
	for(int i=0;i<n;i++)
		v.push_back({price[i],i+1});
	//sort according to stock price
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;i++){
		int price=v[i].first;	//price of current stock
		int stock=v[i].second;  //max amount of stocks that could be purchased
		//if we can purchase maximum quantity of stock for the day
		if(price*stock<=k){
			ans=ans+stock;		// increasenumber of stocks purchased
			k=k-price*stock;	//deduct the spent amount from your total amount
		}
		else{
			//if we cant purchase the maximum qty of stocks
			//then adding the qty we can buy using k amount of money
			ans=ans+(k/price);
			k=k-stock*(k/price);
		}
	}
	return ans;
}


int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
    cout << buyMaximumProducts(n, k, price) << endl;
    return 0;
}