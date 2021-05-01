/*IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go
  to food connection and get P(P<=1000) pratas packed for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8).
  A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on
  (he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 
  mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does 
  not have enough time for the 4th prata). The webmaster wants to  know the minimum time to get the order done. Please write a program to 
help him out. */


#include <bits/stdc++.h>
using namespace std;

//function checks whether all chefs combined can complete the ordered parathas in given mid time
bool check(int *a,int n,int par,int mid)
{
	int time=0;
	int paratha=0;
	for(int i=0;i<n;i++)
	{
		time=a[i];
		int j=2;
		while(time<=mid)
		{
			paratha++;
			time=time+a[i]*j;
			j++;
		}
		if(paratha>=par)
			return true;
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	//test cases
    while(t--)
	{
		//par-ordered paratha ,n-no of chefs
		int par,n;
		cin>>par>>n;
		int a[n];  //ranks of chefs
		for(int i=0;i<n;i++)
			cin>>a[i];
		//talking time as a space in binary search
        int lb=0;
		int ub=1e8; //setting ub to max time that can be taken
		int ans=0;
		while(lb<=ub)
		{
			int mid=(lb+ub)/2;
            //if all the chefs can complete he order in mid time then ans is mid
			if(check(a,n,par,mid))
			{
				ans=mid;    //saving mid and further checking if chef can complete order in less than mid  
				ub=mid-1;   //hence moving ub to mid-1
			}
            //if chefs can complete order in mid then try to increase the time 
			else
				lb=mid+1;   //increse time by incresing lb
		}
		cout<<ans<<endl;
	}
	return 0;
}
