/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
Example 1:
Input: nums1 = [1,3], nums2 = [2]	Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]	Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]	Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]		Output: 1.00000                                    */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        //res-store merge sorted array
        vector<int> res;
        //usaing mergeSort Technique to merge 2 sorted array
        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]<nums2[j])
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);    
        }
        while(i<nums1.size())
            res.push_back(nums1[i++]);
        while(j<nums2.size())
            res.push_back(nums2[j++]);
        
        //if merged array size is even then average of two middle elements is the median
        if(res.size()%2==0)
        {
            int temp=res[(res.size()/2)-1]+res[res.size()/2];
            return temp/2.0;
        }
        //In case of odd number of elements the middle element is the median
        else
        {
            return res[res.size()/2]/1.0;
        }
    }
};