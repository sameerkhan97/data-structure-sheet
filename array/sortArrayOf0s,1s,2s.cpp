//Given an array of nums containing only 0s, 1s, and 2s; sort the array in ascending order

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,mid=0,h=nums.size()-1;
       //iterate mid in the array and perform actions accordingle to mid element
        while(mid<=h)
        {
            switch(nums[mid])
            {
                //if mid is at 0 then swap it with l 
                case 0:swap(nums[l],nums[mid]);
                        mid++;l++;break;
                //if//mid is at 1 just increase mid
                case 1:mid++;break;
                //when mid is 2 swap it with h and decrease h only
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
