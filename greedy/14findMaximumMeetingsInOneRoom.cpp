/*There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of 
  meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples: 
Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
Output : 1 2 4 5 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
Output : 6 7 1 		*/
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