/* There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and
   end[i] is finish time of meeting i.What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting
   can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 4
Explanation:Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

Example 2:
Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
*/

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    //comparattor funtion to sort start,end pairs
    static bool comparator(pair<int,int> p1,pair<int,int> p2){
        if(p1.second<p2.second) return true;
        else if(p1.second>p2.second) return false;
        //if ends of 2 meetings are same then sort in ascending order of start of meet
        else if(p1.first<p2.first) true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meet(n);
        for(int i=0;i<n;i++)  meet[i]={start[i],end[i]};
        //sorting start,end pair in ascending order of end
        sort(meet.begin(),meet.end(),comparator);
        //i to point at 1st meet and j to 2nd meet
        int i=0,j=1;
        int count=1;
        while(j<n){
            //if the current meet start time is after thelast meets end time 
            //then it can be completed 
            if(meet[j].first>meet[i].second){
                count++;
                i=j;    //poinmting i to the next possible meet
                j++;
            }
            //just iterate toward meets untill you find possible meet
            else
                j++;
        }
        return count;
    }
};