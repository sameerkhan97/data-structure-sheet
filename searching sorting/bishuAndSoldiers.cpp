/*Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round 
  Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). 
  After each round, All the soldiers who are dead in previous round will reborn.Such that in each round there will be N soldiers to fight. 
  As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and total sum of their powers.


Sample Input            Sample Output
7                       3 6
1 2 3 4 5 6 7           7 28
3                       2 3
3
10
2

 */
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;	//no. of rounds			
	int a[n];
	//making an array of rounds
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n);
	//storing prefix sum of each round in new array preSum
	int preSum[n+1];
	preSum[0]=0;
	//inserting values in preSum
	for(int i=1;i<=n;i++)
		preSum[i]=preSum[i-1]+a[i-1];

	//test cases
    int q;
	cin>>q;

	while(q--)
	{
		//x-power of bishu 
		int x;
		cin>>x;
		//no. of soldier bishu can beat
		int index=upper_bound(a,a+n,x)-a;
		//preSum[index]-total sum of their power
		cout<<index<<" "<<preSum[index]<<endl;
	}
	return 0;

}