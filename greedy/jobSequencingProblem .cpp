/*Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job
 can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and 
 the number of jobs done.
Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job
Example 1:
Input:N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40). */

// Prints minimum number of platforms reqquired 
// This function is used for sorting all jobs according to profit 
bool comparison(Job a, Job b) 
{ 
     return (a.profit > b.profit); 
} 
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    
    sort(arr, arr + n, comparison); 
    int maxi = arr[0].dead;
    for(int i = 1;i<n;i++) {
        maxi = max(maxi, arr[i].dead); 
    }
    
    int slot[maxi + 1];   
  
    for (int i=0; i<=maxi; i++) 
        slot[i] = -1; 
        
    int countJobs = 0, jobProfit = 0;
  
    for (int i=0; i<n; i++) 
    { 
       for (int j=arr[i].dead; j>0; j--) 
       { 
          if (slot[j]==-1) 
          { 
            slot[j] = i; 
            countJobs++; 
            jobProfit+=arr[i].profit;
            break; 
          } 
       } 
    } 
    
    return make_pair(countJobs, jobProfit); 
} 