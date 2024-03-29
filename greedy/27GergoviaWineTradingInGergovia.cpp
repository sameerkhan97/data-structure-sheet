/* Question Link : https://www.spoj.com/problems/GERGOVIA/
Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city.
 Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, demand and supply is always the same, so that each 
 inhabitant gets what he wants.
There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants
 of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.
In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are built 
along a straight line with equal distance between adjacent houses. Transporting one bottle of wine from one house to an adjacent house results
 in one unit of work.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(true)
	{
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		vector<pair<int,int>> buy;
		vector<pair<int,int>> sell;
		
		for(int i=0;i<n;i++){
			if(a[i]>0)
				buy.push_back({a[i],i});
			else
				sell.push_back({a[i],i});
		}
		int ans=0;
		int i=0,j=0;
		while(i<buy.size() && j<sell.size()){
			int x=min(buy[i].first,-sell[j].first);
			int diff=abs(buy[i].second-sell[j].second);
			if(buy[i].first==0)	i++;
			if(sell[i].first==0) j++;
		}
		cout<<"\nAnswer is "<<ans;
		cin>>n;
		if(n==0) break;
	}
}