/*Given a square matrix, turn it by 90 degrees in a clockwise direction.

Example 1: 
Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

Example 2:
Input:
1 2
3 4
Output:
3 1
4 2 

Example 3:
Input :
00 01 02 
10 11 12 
20 21 22
Output:
20 10 00
21 11 01 
22 12 02
Explaination :
After rotating the matrix by 90 degrees in clockwise direction, indices transform into
20 10 00  current_row_index = 0, i = 2, 1, 0 
21 11 01 current_row_index = 1, i = 2, 1, 0 
22 12 02  current_row_index = 2, i = 2, 1, 0

Observation: In any row, for every decreasing row index i, there exists a constant column index j, such that j = current_row_index. 
This pattern can be printed using 2 nested loops. */


void rotate90Clockwise(int arr[N][N])
{
	int ans[N][N];
	// printing the matrix on the basis of
	// observations made on indices.
	//inserting  elements in matrix using observations
    for (int j = 0; j < N; j++)
	{
		int k=0;
		for (int i = N - 1; i >= 0 && k<N; i--)
			ans[j][k++]=arr[i][j];
	}
    //matrix will be printed which will be 90rotation of original matrix
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
}
 