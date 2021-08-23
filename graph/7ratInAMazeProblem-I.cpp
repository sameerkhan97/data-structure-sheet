/* Question Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible 
path that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left),
'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix
represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:
Input:N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}

Output: DRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Example 2:
Input: N = 2
m[][] = {{1, 0},
         {1, 0}}
Output: -1
Explanation: No path exists and destination cell is blocked. */

class Solution{
    public:
    
    vector<string> v;

    void dfs(int i,int j,string s,vector<vector<int>> m,int n,vector<vector<int>> &vis){
        //bounddary conditions according to size of matrix
        if(i<0 || i>=n || j<0 || j>=n)  return;
        //if current element is blocked or already visited then retturn 
        if(m[i][j]==0 || vis[i][j]==1)  return;
        //if we have reached the destination point
        if(i==n-1 && j==n-1){
            v.push_back(s);
            return;
        }
        //mark the current element visted
        vis[i][j]=1;
        
        //travell in all four directons from current element
        dfs(i+1,j,s+"D",m,n,vis);
        dfs(i-1,j,s+"U",m,n,vis);
        dfs(i,j+1,s+"R",m,n,vis);
        dfs(i,j-1,s+"L",m,n,vis);
        
        //mark current element un visited so that it can be used in some other path
        vis[i][j]=0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        v.clear();
        int MAX=m.size();
        //vis vector to mark the visiting elements
        vector< vector<int> > vis(MAX,vector<int>(MAX));
        //if starting or destination pointing is blocked then path cant be determined
        if(m[0][0]==0 || m[n-1][n-1]==0) return v;
        string s="";
        dfs(0,0,s,m,n,vis);
        sort(v.begin(),v.end());
        return v;
    }