// Q-Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long pr=1,max=-1020;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	            pr=arr[i];
	        else
	            pr=(-arr[i]);
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[j]<0)
	                pr=pr*(-arr[j]);
	            else
	                pr=pr*arr[j];
	            if(pr>max)
	                max=pr;
	        }
	    }
	    return max;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends