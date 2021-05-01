/*You are given N number of books. Every ith book has Ai number of pages. You have to allocate books to M number of students. There can be
 many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all
 these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum
 of those in all the other permutations and print this minimum value. 
 
 Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Example 1:
Input: N = 4 , A[] = {12,34,67,90} , M = 2
Output: 113
Explanation: Allocation can be done in following ways: {12} and {34, 67, 90} , Maximum Pages = 191 {12, 34} and {67, 90} , 
 Maximum Pages = 157 {12, 34, 67} and {90} , Maximum Pages =113 Therefore, the minimum of these cases is 113, which is selected as the output.

Example 2:
Input:N = 3 , A[] = {15,17,20} , M = 2
Output: 32
Explanation: Allocation is done as {15,17} and {20}   */


class Solution {
  public:
 
    //function will return true if we can distribute given range (mid) to m students
    //function will return false if we can not distribute given range (mid) to m students
    bool solve(int a[],int n,int mid,int m)
    {
        //sum-total pages that can be allocated to each students ,it must be < mid
        int sum=0;
        int stu=1;//starting distribution from 1 student
        for(int i=0;i<n;i++)
        {
            //if first book  page is greater than range then it cnt be distributed hence return false
            if(a[i]>mid)
                return false;
            //when distribution of pages to one stuudent reaches its limit i.e mid
            if(sum+a[i]>mid)
            {
                //then start distributing new student  
                stu++;
                sum=a[i];
                //if new student created,crosses the total no. of students 
                if(stu>m)
                    return false;
            }
            else
            //keep adding pages to a student untill it get upto mid
                sum+=a[i];
        }
        return true;
    }
    
    
    int findPages(int arr[], int n, int m) {
        int lb=0;
        int s=0;
        int ans;
        //sum the total pages of books
        for(int i=0;i<n;i++)
            s+=arr[i];
        //total pages  of book will be our upperBound
        int ub=s;
        while(lb<=ub)
        {
            //middle element of current upper and lower bound
            int mid=(lb+ub)/2;
            //if solve return true then we understand that we can distribute current range(mid) of pages 
            //to m student between ub & lb pages
            //after getting answer further minimize the upper bound to get minimum pages
            if(solve(arr,n,mid,m))
            {
                ans=mid;
                ub=ub=mid-1;
            }
            //if solve return false means cant distribute current range(mid) of pages to m students
            //increasing the lower bound to further check for higher range(mid)
            else
                lb=mid+1;
        }
        return ans;
    }
};
