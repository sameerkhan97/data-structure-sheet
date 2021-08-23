/* Question link : https://leetcode.com/problems/flood-fill/
 An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the
starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of 
the aforementioned pixels with newColor.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same 
color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]   */
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,vector<vector<int>>& vis,int oldColor,int newColor,int n,int m){
        //check bounding conditions 
        if(i<0 || j<0 || i>=n ||j>=m)   return;

        //if current node is already visited or have diff color than old color of its adjecent node
        //then we need to return
        if(image[i][j]!=oldColor || vis[i][j]==1)   return;
        
        //if this node isn't visited and have same color as old color of Adjecent element
        //then mark it visited and change its color to new color
        vis[i][j]=1;
        image[i][j]=newColor;
        
        //tarverse in all 4 possible directions of matrix and check for same colors
        dfs(i+1,j,image,vis,oldColor,newColor,n,m);
        dfs(i-1,j,image,vis,oldColor,newColor,n,m);
        dfs(i,j+1,image,vis,oldColor,newColor,n,m);
        dfs(i,j-1,image,vis,oldColor,newColor,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //taking row
        int x=image.size();
        //taking columns
        int y=image[0].size();
        //creating vis array to mark visited locations
        vector< vector<int> > vis(x,vector<int> (y,0));
        //saving the old color to check, for adjecent elemnt with same color
        int oldColor=image[sr][sc];
        dfs(sr,sc,image,vis,oldColor,newColor,x,y);
        return image;
    }
};