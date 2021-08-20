/*Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only 
  one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number
  of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

Example 1:
Input: N = 4 , Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Example 2:
Input: N = 5 , Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
Output:2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //arranging array in descending order of profit
        sort(arr,arr+n,comp);
        //creating bool array to check available work spcae i.e deadline
        bool done[n]={0};
        vector<int> ans(2); //ans[0]:no. of jobs ans[1]:total profit 
        for(int i=0;i<n;i++){
            //for every job[i] will iterate through the done to check 
            //corresdonding work spaces available to complete thejob
            for(int j=min(n,arr[i].dead-1);j>=0;j--){
                //when the work space is empty
                if(!done[j]){
                    ans[0]+=1;
                    ans[1]=ans[1]+arr[i].profit;
                    done[j]=true;   //mark space as occupied
                    break;
                }
            }
        }
        return ans;
    } 
};