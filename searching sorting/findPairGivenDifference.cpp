/*Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements 
  in the array whose difference is N.

Example 1:
Input: L = 6, N = 78   arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.

Example 2:
Input: L = 5, N = 45   arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.  */ 



bool findPair(int a[], int size, int n){
    int i=0;
    //copy array to vector
    vector<int> arr(a+0,a+size);

    //sorting the vector
    sort(arr.begin(),arr.end());
    
    //initialize two pointer on 1st and 2nd element
    int left=0,right=1;
    while(left<size && right<size)
    {
        if(right!=left && arr[right]-arr[left]==n)
            return true;
        //whenever the differenece is small then increase the right pointer 
        //pointer will point to greater value nd difference will increase
        else if(arr[right]-arr[left]<n)    
            right++;
        //whenever the differenece is greater then increase the left pointer 
        //pointer will point to greater value nd difference will decrease
        else if(arr[right]-arr[left]>n)
            left++;
    }
    return false;
}
