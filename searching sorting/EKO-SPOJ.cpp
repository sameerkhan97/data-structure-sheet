/*Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take 
  down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and
cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. 
For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining
tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off 
the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as
possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Example 1:
Input:
4 7
20 15 10 17
Output:
15

eXAMPLE 2:
Input:
5 20
4 42 40 26 46
Output:
36 */



#include <bits/stdc++.h>
using namespace std;
bool solve (int a[],int n,int m,int mid)
{
    //sum count total no of woods we got after cutting each tree
	int sum=0;
	for(int i=0;i<n;i++)
	{
        //if current tree height is > than out cutting parameter then add its upper remaining height to sum
		if(a[i]>mid)
			sum+=(a[i]-mid);
	}
    //if the total woods got after cutting fullfill the requirement of m-woods then return true
	if(sum>=m)
		return true;
	else
		return false;
}
int main() {
	
    //input number of trees -n,and requirement of wood-m
	int n,m;
	cin>>n>>m;
	int a[n];
    //array a having height of all trees
	for(int i=0;i<n;i++)
		cin>>a[i];
	int lb=0;
	int ans=0;
    //ub-maximum height tree 
	int ub=*max_element(a,a+n);
	while(lb<=ub)
	{
        //selecting mid range to cutt the tree 
		int mid=(lb+ub)/2;
        //if solve return true meaning we can complete our requirement of m wood by cutting trees from mid
		//ans will store that mid value
        //then we will move upper side to check if we cn fill requirement by cutting less amount of tree
        if(solve(a,n,m,mid))
		{
			ans=mid;
			lb=mid+1;
		}
        //if solve return false meaning we can't complete our requirement of m wood by cutting trees from mid
        //we now tr to cuitt tree lower than mid and check if it fill our requirement or not
		else
			ub=mid-1;
	}
	cout<<ans<<" ";
} 