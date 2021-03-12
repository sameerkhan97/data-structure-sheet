/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 In this case, 6 units of rain water (blue section) are being trapped.

Problem Link : https://leetcode.com/problems/trapping-rain-water/ */

//Brute Force :
class Solution {
public:
    int trap(vector<int>& a) {
        //sum will store total water trapped
        int sum=0;
        for(int i=0;i<a.size();i++)
        {
`           //largest number on left and right side of a[i]
            int leftMax=0,rightMax=0;
            for(int j=i;j>=0;j--)
            {
                if(a[j]>leftMax)
                    leftMax=a[j];
                
            }
            for(int j=i+1;j<a.size();j++)
            {
                if(a[j]>rightMax)
                    rightMax=a[j];
                
            }
            //smaller between leftmax,rightmax will be stored in Min
            int min;
            if(leftMax<rightMax)
                min=leftMax;
            else
                min=rightMax;
            //diff between min-a[i] will give us water traped in a[i]
            //amount traped in a[i] will be added with tgotal water trapped i.e Sum.
            if(min-a[i]>0)
                sum=sum+min-a[i];
        }
        return sum;
    }
};


//Optimal Approach :
class Solution {
public:
    int trap(vector<int>& a) {
         int l=0,r=a.size()-1,leftMax=0,rightMax=0,sum=0;
         while(l<=r)
         {
             if(a[l]<=a[r])
             {
                 if(a[l]>=leftMax)
                     leftMax=a[l];
                 else
                     sum=sum+leftMax-a[l];
                 l++;
             }
             else
             {
                if(a[r]>=rightMax)
                        rightMax=a[r];
                 else
                     sum=sum+rightMax-a[r];
                 r--;
             }
         }
        return sum;
    }
};
