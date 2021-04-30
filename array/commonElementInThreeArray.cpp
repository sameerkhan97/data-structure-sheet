/*Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?
Example 1:
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C. */

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            //three pointers to traverse each array
            int x=0,y=0,z=0;
            //last will contain last element added in vector so we wont add copy  element
            int last=0; 
            //keep traversing array untill any one of them ends
            while(x<n1 && y<n2 && z<n3)
            {
                //when we find common element then storing it in vector
                if(A[x]==B[y] && B[y]==C[z] && A[x]!=last)
                {
                    ans.push_back(A[x]);
                    last=A[x];
                    x++;
                    y++;
                    z++;
                }
                //if B[y] is smaller then increment its pointer
                else if(A[x]>B[y])
                    y++;
                //if C[z] is smaller then increment its pointer
                else if(B[y]>C[z])
                    z++;
                //if A[x] is smaller then increment its pointer
                else
                    x++;
            }
            return ans;
        }

};