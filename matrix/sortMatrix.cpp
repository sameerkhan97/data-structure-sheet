/*Given an NxN matrix Mat. Sort all elements of the matrix.

Example 1:

Input:N=4       Mat=[[10,20,30,40],
                    [15,25,35,45], 
                    [27,29,37,48],
                    [32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50

Example 2:
Input: N=3      Mat=[[1,5,3],[2,8,7],[4,6,9]]
Output:
1 2 3 
4 5 6
7 8 9  */

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> matrix) {
        vector<int> ans;
        //copying matrix into ana array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                ans.push_back(matrix[i][j]);
        }
        //sorting the array
        sort(ans.begin(),ans.end());
        int c=0;
        //copying sorted array back into matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                matrix[i][j]=ans[c++];
        }
        return matrix;
    }
};
