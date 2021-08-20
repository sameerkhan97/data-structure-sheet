// Question Link : https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems#
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string s;
	    cin>>s;
	    unordered_map<int,int> m;
	    int max=0;
	    for(int i=0;i<s.size();i++){
	        m[s[i]]++;
	        if(m[s[i]]>max)
	            max=m[s[i]];
	    }
	    if(max<=s.size()-max+1)
	        cout<<"1\n";
	    else
	        cout<<"0\n";
	}
}