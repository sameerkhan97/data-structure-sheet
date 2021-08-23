/*Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:
Input:   
             1------2
            / \      \
           0   \      \
                \      \
                 4------3
Output: 1
Explanation: 1->2->3->4->1 is a cycle.

Example 2:
Input:  
         0
    1 ----- 2
           /        
          3
Output: 0
Explanation: No cycle in the graph.
*/
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool dfs(int V,int par,vector<bool> &vis,vector<int>adj[]){
	    vis[V]=true;
	    for(auto x: adj[V]){
	        if(!vis[x]){
	            bool f=dfs(x,V,vis,adj);
	            if(f)   return true;
	        }
	        else if(par!=x)
	            return true;
	    }
	    return false;
	}
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            bool f = dfs(i, -1, vis, adj);
	            if(f)
	                return true;
	        }
	    }
	    return false;
	}
};