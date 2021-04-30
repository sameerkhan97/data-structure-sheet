/*Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 
Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array 
      i.e., a stable sort.
Example 1:
Input: arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output: 15 7 5 3 9 6 2 4 32
Explanation: The integers in their binary representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is: {15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
 
Example 2:
Input: arr[] = {1, 2, 3, 4, 5, 6};
Output: 3 5 6 1 2 4
Explanation:
3  - 0110
5  - 0101
6  - 0110
1  - 0001
2  - 0010
4  - 0100
hence the non-increasing sorted order is {3, 5, 6}, {1, 2, 4}                   */

//count of set bits means count of '1's in binary representation of integer
class Solution{
    public:
    
    static bool comp(int a,int b)
    {
        //builtin_popcount method is used to count set bit of an integer
        return __builtin_popcount(a)>__builtin_popcount(b);
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        //sort the array using comp methode
        //stable keyword is used to sort element with same set bitts count according to their position in array 
        stable_sort(arr,arr+n,comp);
    }
};
