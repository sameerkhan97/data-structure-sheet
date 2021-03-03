//Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
//Brute Force : marking all positions  of change with -786 and in last replacing them with 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int m=0;m<matrix.size();m++)
        {
            for(int n=0;n<matrix[0].size();n++)
            {
                if(matrix[m][n]==0)
                {
		   //when 0 is found then mark all its column and row with a unique key(i choose -786)
                    for(int i=0;i<matrix[0].size();i++)
                    {
                        if(matrix[m][i]!=0)
                            matrix[m][i]=-786;      
                    }
                    for(int i=0;i<matrix.size();i++)
                    {
                        if(matrix[i][n]!=0)
                            matrix[i][n]=-786;
                    }
                }
            }
        }
	//iterate in whole matrix and whenever find unique key replace it with 0
        for(int m=0;m<matrix.size();m++)
        {
            for(int n=0;n<matrix[0].size();n++)
            {
                if(matrix[m][n]==-786)
                {
                    matrix[m][n]=0;
                }
            }
        }
    }
};

//Optimal approach : take 2 dummy array and mark row and column for every zero
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row[matrix.size()],col[matrix[0].size()];
        for(int m=0;m<matrix.size();m++)
        {
            for(int n=0;n<matrix[0].size();n++)
            {
		//when found 0 then mark its column and row index as 0 in row,col array
                if(matrix[m][n]==0)
                {
                    row[m]=0;
                    col[n]=0;
                }
            }
        }
	//iterate whole matrix and for any element if row/col array has 0 index then mark it as 0
        for(int m=0;m<matrix.size();m++)
        {
            for(int n=0;n<matrix[0].size();n++)
            {
                if(row[m]==0 || col[n]==0)
                    matrix[m][n]=0;
            }
        }
    }
};
//Most Optiaml :instead of using extra space used first row,column as array 
0class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        for(int m=0;m<matrix.size();m++)
        {
	   //instead of using seprate space ,use 1st row and columns as array
            if(matrix[m][0]==0) col0=0;
            for(int n=1;n<matrix[0].size();n++)
            {
		//whenever 0 found (except in 1st row/col) then marked 1 row's corresponding index and 1st column's corresponding index as 0 
                if(matrix[m][n]==0)
                    matrix[m][0]=matrix[0][n]=0;
            }
        }
	//iterate whole matrix and for every element check its index in 1st row and column if anyone is marked 0 then mark element as 0
        for(int m=matrix.size()-1;m>=0;m--)
        {
            for(int n=matrix[0].size()-1;n>=0;n--)
            {
                if(matrix[m][0]==0 || matrix[0][n]==0)
                    matrix[m][n]=0;
            }
            if(col0==0)
	        matrix[m][0]=0;
        }
    }
};
