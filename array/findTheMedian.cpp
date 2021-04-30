/*Given an array arr[] of N integers, calculate the median
 
Example 1: 
Input: N = 5    arr[] = 90 100 78 89 67
Output: 89

Example 2:
Input: N = 4    arr[] = 56 67 30 79â€‹
Output: 61    */

class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    //After sorting,In case of even number of elements average of two middle elements is the median
 	           if(v.size()%2==0)
		    {
		        int res=v[(v.size()/2)-1]+v[v.size()/2];
		        return  res/2;
		    }
              	    //In case of odd number of elements the array middle element is the median
	 	    else
		    {
		        return v[v.size()/2];
		    }
		}
};