/*  Question Link  : https://www.spoj.com/problems/ARRANGE/
Scientists at the TIFR, Mumbai, are doing some cutting edge research on the Propagation of Signals. A young researcher comes up with a method 
of progressively amplifying signals, as they progress along a path. The method involves the placing of Amplifiers at regular distances along the
line. Each amplifier is loaded with a number a(i), which is called its amplification factor. The method of amplification is simple: an amplifier
which recieves a signal of strength X, and has Y loaded in it, results in a signal of strength Y^X [ Y to the power X]. In course of his research,
the young scientist tries to find out, that given a set of n amplifiers loaded with a(0), a(1), a(2), ...., a(n-1), which particular permutation
of these amplifiers, when placed at successive nodes, with the initial node given a signal of strength 1, produces the strongest output signal.
this is better illustrated by the following example : 5 6 4
4^(5^(6^1)) is the strength of the strongest signal, which is generated by putting amplifier loaded with 6 in first place, 5 in second place
 and 4 in third place.
Given a list of integers specifying the set of amplifiers at hand, you must find out the order in which they must be placed, to get the highest
signal strength. In case their exist multiple permutations with same output, you should print the one which has bigger amplifiers first.

Input : First line of input contains T, the number of test cases. For each test case first line contains a number ni, which is equal to the 
number of amplifiers available. Next line contains n integers, separated by spaces which denote the values with which the amplifiers are loaded.

Output : Output contains T lines, one for each test case. Each line contains ni integers, denoting the order in which the amplifiers should be
kept such that the result is strongest.

Example
Input:
2
3
5 6 4
2
2 3

Output:
6 5 4
2 3

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int ones=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1)
				ones++;
		}
		sort(a,a+n,greater<int>());
		for(int i=0;i<ones;i++)	cout<<"1 ";
		
		if(n-ones==2 && a[0]==3 && a[1]==2)
			cout<<"2 3 ";
		else{
			for(int i=0;i<n-ones;i++)
				cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
}