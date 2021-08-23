/* Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#
    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Example 1:
Input:
              
Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:
Input:
Output: 0
Explanation: no cycle in the graph
*/

class Solution
{
    public:
    bool solve(int V,vector<int> &vis,vector<int> &order,vector<int> adj[]){
        vis[V]=1;
        order[V]=1;
        for(auto x:adj[V]){
            if(!vis[x]){
                bool c=solve(x,vis,order,adj);
                if(c)
                    return true;
            }
            else if(order[x])
                return true;
        }
        order[V]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> vis(V,0);
	   	vector<int> order(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i] ){
	            bool c=solve(i,vis,order,adj);
	            if(c)
	                return true;
	        }
	    }
	    return false;
	}
};