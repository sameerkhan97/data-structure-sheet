/* Question Link : https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach
  the target position.

Note: The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing

Example 1:
Input:N=6   ,   knightPos[ ] = {4, 5}   ,   targetPos[ ] = {1, 1}
Output:3
Explanation:
Knight takes 3 step to reach from 
(4, 5) to (1, 1):   (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
*/
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    //taking initiial cordinates of knight in x1,y1
	    //and target co-ordinates in x2,y2
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    //if initial pos and target pos are same then we make 0 step
	    if(x1==x2 && y1==y2)    return 0;
	    
	    //taking an array to traverse and count steps according to given co-ordinates
	    int a[1001][1001];
	    //queue will be storing the next step of knight
	    queue<pair<int,int>> q;
	    for(int i=0;i<1001;i++){
	        for(int j=0;j<1001;j++){
	            a[i][j]=0;
	        }
	    }
	    //pushing initial pos to queue
	    q.push(make_pair(x1-1,y1-1));
	    while(!q.empty()){
	        auto curr=q.front();
	        int i=curr.first;
	        int j=curr.second;
	        q.pop();
	        
	        //tarversing in all 8 possible paths of knight
	        //increasing steps, element of each paths destination
	        //in such a way thgat target will store the min step
	        if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and a[i-1][j+2]==0){
	            a[i-1][j+2]=a[i][j]+1;
	            q.push(make_pair(i-1,j+2));
	        }
	        if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and a[i-1][j-2]==0){
	            a[i-1][j-2]=a[i][j]+1;
	            q.push(make_pair(i-1,j-2));
	        }
	        if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and a[i+1][j-2]==0){
	            a[i+1][j-2]=a[i][j]+1;
	            q.push(make_pair(i+1,j-2));
	        }
	        if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n and a[i+1][j+2]==0){
	            a[i+1][j+2]=a[i][j]+1;
	            q.push(make_pair(i+1,j+2));
	        }
	        if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and a[i-2][j-1]==0){
	            a[i-2][j-1]=a[i][j]+1;
	            q.push(make_pair(i-2,j-1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and a[i+2][j-1]==0){
	            a[i+2][j-1]=a[i][j]+1;
	            q.push(make_pair(i+2,j-1));
	        }
	        if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and a[i-2][j+1]==0){
	            a[i-2][j+1]=a[i][j]+1;
	            q.push(make_pair(i-2,j+1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and a[i+2][j+1]==0){
	            a[i+2][j+1]=a[i][j]+1;
	            q.push(make_pair(i+2,j+1));
	        }
	    }
	    return a[x2-1][y2-1];
	}
};