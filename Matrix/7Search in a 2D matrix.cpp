/*Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row. LEET CODE PROBLEM*/
//Optimal approach TC:O(n+m),SC:O(1) :
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int pos=-1;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][m-1])
            {
                pos=i;
                break;
            }
        }
        if(pos==-1) return false;
        for(int i=0;i<m;i++)
        {
            if(matrix[pos][i]==target)
                return true;
        }
        return false;
    }   
};
/*Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, and a number X is given.
 The task is to find whether element X is present in the matrix or not.
 N = 3, M = 3
mat[][] = {(3 30 38),(44 52 54),(57 60 69)}
X = 62
Output:
0  */
class Solution{
public:	
	int matSearch (vector <vector <int>> &matrix, int n, int m, int target)
	{
	    int i=0,j=m-1;
	    while(i<n && j>=0)
	    {
	        if(matrix[i][j]==target)
	            return 1;
	        else if(matrix[i][j]>target)
	            j--;
	        else
	            i++;
	    }
	    return 0;
	}
};
