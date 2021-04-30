/*Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row. LEET CODE PROBLEM */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)  
     int row=-1;
     for(int i=0;i<matrix.size();i++)
     {
         //finding if theres any row where we can find the target
         if(matrix[i][0]<=target and matrix[i][matrix[i].size()-1]>=target)
        {
            row=i;
            break;
        }
     }
    //if there is no row then return false
     if(row==-1)
         return false;
    //if there  is a row then find if it contains target or not
     for(int i=0;i<matrix[row].size();i++)
     {
         if(matrix[row][i]==target)
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
	    //starting with last element of first row
        while(i<n && j>=0)
	    {
	        if(matrix[i][j]==target)
	            return 1;
	        //if element is greater than target then move left in row
            else if(matrix[i][j]>target)
	            j--;
            //if eelement is smaller than target then move downwards in column
	        else
	            i++;
	    }
	    return 0;
	}
};
