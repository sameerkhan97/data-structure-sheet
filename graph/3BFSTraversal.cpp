/* Question Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.Note: One can move from node u to node v only
if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph.
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Example 1:
Input:
           0
        /  |  \
       1   2   3
           /
          4 
Output: 0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3.After this 2 to 4, thus bfs will be
0 1 2 3 4.

Example 2:
Input:
          0 
        /   \
       1     2 
Output: 0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2 3 4. 

*/

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    queue<int> q;
	    vector<int> vis(V,0);
	    //using vis array to mark visited nodes ,to avoid cyclic loop
	    vis[0]=1;
	    //initially pushhing 0  in queue
	    q.push(0);
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        //traversing the adjency matrix of current node and pushing its 
	        //connected node to the graph,keep marking them visited
	        for(auto x: adj[temp]){
	            if(!vis[x]){
	                vis[x]=1;
	                q.push(x);
	            }
	        }
	    }
	    return ans;
	}
};