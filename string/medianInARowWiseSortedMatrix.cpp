/*Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:R = 3, C = 3,     M = [[1, 3, 5], 
                            [2, 6, 9], 
                            [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 
Example 2:
Input: R = 3, C = 1     M = [[1], [2], [3]]
Output: 2 */


class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> ans;
        int i=0,j=0;
        //storing all elements of matrix into array
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        //sort the array to find median easily
        sort(ans.begin(),ans.end());

        //array  size is even the median is avg of 2 middle elements of array
        if(ans.size()%2==0)
             return (ans[(ans.size()/2)-1]+ans[ans.size()/2])/2;
        //array size is odd then median is middle element 
        else
            return ans[ans.size()/2];
    }
};
