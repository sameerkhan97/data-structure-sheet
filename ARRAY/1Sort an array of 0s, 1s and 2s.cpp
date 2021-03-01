//Given an array of nums containing only 0s, 1s, and 2s; sort the array in ascending order

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,mid=0,h=nums.size()-1;
        
        while(mid<=h)
        {
            switch(nums[mid])
            {
                case 0:swap(nums[l],nums[mid]);
                        mid++;l++;break;
                case 1:mid++;break;
                case 2:swap(nums[mid],nums[h]);
                        h--;break;
            }
        }
    }
    void swap(int &a,int &b)
    {
        int t=a;
        a=b;
        b=t;
    }
};