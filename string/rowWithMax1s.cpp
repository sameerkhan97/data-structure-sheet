/*Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has maximum number of 1's.

Example 1:
Input:N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).

Example 2:
Input:N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing). */


class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int max=-1;
	    int row=0;      // keeps track of row; starts at first row
	    int col=m-1;;   // keeps track of column; starts at last column
	    // starting from top right corner
        // go left if you encounter 1
        // do down if you encounter 0
	    while(row<n && col>=0)
	    {
	        if(arr[row][col]==1)
	        {
	            max=row;
	            col--;
	        }
	        else
	            row++;
	    }
	    return max;
	}

};
