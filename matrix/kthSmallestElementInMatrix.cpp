/*Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:N = 4 , K = 3
mat[][] ={{16, 28, 60, 64},
          {22, 41, 63, 91},
          {27, 50, 87, 93},
          {36, 78, 87, 94 }}
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:N = 4 , K = 7
mat[][] ={{10, 20, 30, 40}
          {15, 25, 35, 45}
          {24, 29, 37, 48}
          {32, 33, 39, 50}}
Output: 30
Explanation: 30 is the 7th smallest element. */


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int> ans;
    //inserting matrix element into rray
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            ans.push_back(mat[i][j]);
    }
    //sorting the array so we can find kth smallest element easily 
    sort(ans.begin(),ans.end());

    return ans[k-1];
}