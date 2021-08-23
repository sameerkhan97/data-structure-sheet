/* Question Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
Given a connected undirected graph. Perform a Depth First Traversal of the graph. Note: Use recursive approach to find the DFS traversal
 of the graph starting from the 0th vertex from left to right according to the graph..


Example 1:
Input:
          0
        / | \
       1  2  4
            /
           3

Output: 0 1 2 4 3
Explanation: 
0 is connected to 1, 2, 4.
1 is connected to 0.
2 is connected to 0.
3 is connected to 4.
4 is connected to 0, 3.
so starting from 0, it will go to 1 then 2, then 4, and then from 4 to 3.Thus dfs will be 0 1 2 4 3.

Example 2:
Input:
         0
        | \
        1  3
       /
      2
Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2,then back to 0 then 0 to 3, thus dfs will be 0 1 2 3.
*/
class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void solve(int V,vector<int> &vis,vector<int> adj[]){
        vis[V]=1;   //first mark current node as visited
        ans.push_back(V);//move the node into answer
        //in adjency listt,look for the child ofthe current ode
        //and keep calling function with deep nodes
        for(auto x:adj[V]){
            if(!vis[x])
                solve(x,vis,adj);
        }
    }
    
    vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    ans.clear();
	    vector<int> vis(V,0);   ..keep track of visited element
	    solve(0,vis,adj);
	    return ans;
	}
};