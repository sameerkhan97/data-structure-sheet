/* Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it
Example : 
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]] */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> p(numRows);
        for(int i=0;i<numRows;i++)
        {
            p[i].resize(i+1);
            p[i][0]=p[i][i]=1;
            for(int j=1;j<i;j++)
            {
                p[i][j]=p[i-1][j-1]+p[i-1][j];
            }
        }
        return p;
    }
};