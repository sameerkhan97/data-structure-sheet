/*54.Given an m x n matrix, return all elements of the matrix in spiral order.
Example :
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5] 
Explaination: 
	 1 → 2 → 3
		 ↓
	 4 → 5   6
	 ↑	 ↓
	 7 ← 8 ← 9


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       /*top-  first row of remaining array
         bottom- last row of remaining array
         left- first column of remaining array
         right-last column of remaining array */
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        
        vector<int> ans;
        while(top<=bottom && left<=right)
        {
            //pushing first row of remaining matrix into ans
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            //deleting the added row
            top++;
            
            //pushing rightMost column of remaining matrix into ans
            for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            //deleting the added columns
            right--;
                
            //if we still have rows left
            if(top<=bottom)
            {
                //pushing the last row of remaining matrix into ans
                for(int i=right;i>=left;i--)
                    ans.push_back(matrix[bottom][i]);
                //deleting the added row
                bottom--;
            }
            //if we still have columns left
            if(left<=right)
            {
                //pushing the leftMost column of remaining matrix into ans
                for(int i=bottom;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                //deleting the added column
                left++;
            }
        }
        return ans;
    }
};