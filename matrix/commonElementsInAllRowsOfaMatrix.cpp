/*Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
Example: 
Input:mat[4][5] = {{1, 2, 1, 4, 8},
      	          {3, 7, 8, 5, 1},
                  {8, 7, 7, 3, 1},
                  {8, 1, 2, 7, 9}};
Output:1 8 or 8 1
Explaination : 8 and 1 are present in all rows  */



void getCommonElementinRow(int matrix[M][N])
{
    //map will store occurancy of elements of 1st row
    unordered_map<int,int> map;
    for(int i=0;i<N;i++)
    	map[matrix[0][i]]=1;
    	
    //checking for occurancy of elements of 1st row
    for(int i=1;i<M;i++)
    {
    	for(int j=0;j<N;j++)
    	{
		//if the element occured in previous row then increment occurancy
    		if(map[matrix[i][j]]==i)
    		{
    			map[matrix[i][j]]=i+1;
    			//if its the last row of matrix
			if(i==M-1)
    				cout<<"\n"<<matrix[i][j];
    		}
    	}
    }
}