//Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
//Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        int i,j,maxl=0,minl=0,max=arr[0],min=arr[0];
        for(i=1;i<n;i++)
        {
            if(arr[i]>max){ 
                max=arr[i];
                maxl=i;
            }
            if(arr[i]<min){
                min=arr[i];
                minl=i;
            }
        }
        for(i=0;i<n;i++)
        {
                if(arr[i]+k>max-k)
                    arr[i]=arr[i]-k;
                else if(arr[i]-k<min+k)
                    arr[i]=arr[i]+k;
        }
        
        int difference=arr[maxl]-arr[minl];
        return difference;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends