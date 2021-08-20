#include <bits/stdc++.h>
using namespace std;

//compare on basis on burst time
bool comp(vector<int> a,vector<int> b){
	if(a[1]==b[1]){
		//if burst time is same then compare for arrival time 
		if(a[2]==b[2])
		//if arrival time too is same then compare for id
			return a[0]<b[0];
		else 
			return a[2]<b[2];
	}
	return a[1]<b[1];
}

int main() {
	int n;
	cout<<"Enter Size";
	cin>>n;
	//taking id, arrival time, burst-time
	vector<vector<int>> v(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	vector<int> ans;
	sort(v.begin(),v.end(),comp);
	
	//using priority queue so we will get shoprted in the top automatically
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq;
	//pushing first process in reverse order i.e burst time,arrival time, id 
	pq.push({v[0][2],v[0][1],v[0][0]});
	int i=1;
	int currTime=0;
	while(!pq.empty()){
		//taking id and burst time for current process
		int burst_time=pq.top()[0];
		int id=pq.top()[2];
		pq.pop();
		//push id into answer
		ans.push_back(id);
		//now increase the tine required by adding burst time
		currTime+=burst_time;
		while(true){
			//during the current process execution we push all arriving processes in pq
			if(i<n && v[i][1]<=currTime){
				pq.push({v[i][2],v[i][1],v[i][0]});
				i++;
			}
			else
				break;
		}	
	}
	cout<<"\nSJF Scheduled Processes are : ";
	for(i=0;i<n;i++)
		cout<<ans[i]<<"  ";
}