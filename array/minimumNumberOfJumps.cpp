/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the
 minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, 
then you cannot move through that element.
Example 1:
Input:
N=11 
arr=1 3 5 8 9 2 6 7 6 8 9 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
Example 2:
Input :
N= 6
arr= 1 4 3 2 6 7
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element. */



class Solution{
  public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int minJumps(int arr[], int n){
        if(arr[0]==0)
         return -1;
        if(n==1)
         return 0;
       int maxR=arr[0],step=arr[0],jump=1;
       //now iterating from 2nd element
       for(int i=1;i<n;i++)
       {
           //if i have reached lst index and steps are remained then return number of jumps
           if(i==n-1 && step)
                return jump;
            //we can jump upto max range between i+arr[i]
            maxR=max(maxR,i+arr[i]);
            //whenever we pass an element then 1 step is decreased
            step--;
            if(step<0)
                return -1;
            //if there are no more steps then
            if(step==0)
            {
                //after going all steps we have successfully jumped 1 time
                jump++;
                //if i reaches ahead of our max Range and we are stucked in max Range then we cant reach end
                if(i>=maxR)
                    return -1;
                //re-initialize steps between i and maxRange
                step=maxR-i;
            }
       }
    }
};