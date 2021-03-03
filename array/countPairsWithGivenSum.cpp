//Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        //c-count number of pairs
        int c=0;
        for(int i=0;i<n;i++)
        {
            //pairing a[i] with all forward element to check if sum equals k
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j]==k)
                    c++;    //when sum equals k count the pair
            }
        }
        return c;
    }
};
int main() {
    //n-array size,k-sum to be checked
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";  
        return 0;
}  
