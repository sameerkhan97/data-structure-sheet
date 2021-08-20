/*Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway
  station so that no train is kept waiting. Consider that all the trains arrive on the same day and leave on the same day. Arrival and 
  departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At
  any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases,
   we need different platforms.

Example 1:
Input: n = 6    ,   arr[] = {0900, 0940, 0950, 1100, 1500, 1800}    ,   dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: Minimum 3 platforms are required to safely arrive and depart all trains.

Example 2:
Input: n = 3    ,   arr[] = {0900, 1100, 1235}  ,   dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to safely manage the arrival and departure of all trains.  */

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        //-.sorting arrival and departure array
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	int ans=1;
    	//we will consider that 1st train i.e arr[0] is already at pl;atform hence ans=1
    	//so we compare the departure time with arrival of every train
    	while(i<n){
    	    if(arr[i]<=dep[j]){
    	        ans++;
    	        i++;
    	    }
    	    else{
    	        i++;
    	        j++;
    	    }
    	}
    	return ans;
    }
};