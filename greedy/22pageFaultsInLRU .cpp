/*In operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced 
when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces
one of the existing pages with a newly needed page.Given a sequence of pages in an array pages[] of length N and memory capacity C, find the
number of page faults using Least Recently Used (LRU) Algorithm. 

Example 1:
Input: N = 9, C = 4     ,   pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}
Output: 8
Explaination: memory allocated with 4 pages 5, 0, 1, 3: page fault = 4
page number 2 is required, replaces LRU 5: page fault = 4+1 = 5
page number 4 is required, replaces LRU 0: page fault = 5 + 1 = 6
page number 1 is required which is already present: page fault = 6 + 0 = 6
page number 0 is required which replaces LRU 1: page fault = 6 + 1 = 7
page number 5 is required which replaces LRU 3: page fault = 7 + 1  =8.
*/

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // To store elements in memory of size c
        vector<int> v;
        int pgFault=0;
        for(int i=0;i<N;i++){
            // Find if element is present in memory or not
            auto it=find(v.begin(),v.end(),pages[i]);
            //if page isn't in memory
            if(it==v.end()){
                // If memory is full
                if(v.size()==C){
                    // Remove the first element as it is least recently used
                    v.erase(v.begin());
                }
                // Add the recent element into memory
                v.push_back(pages[i]);
                //increment the page fault
                pgFault++;
            }
            else{
                // If element is present remove the element
               // and add it at the end as its the most recent element
                v.erase(it);     
                v.push_back(pages[i]);
            }
        }
        return pgFault;
    }
};