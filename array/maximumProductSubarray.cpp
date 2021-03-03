// Q-Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
#include <bits/stdc++.h>
using namespace std;
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
	            pr=(-arr[i]);	//if array element is negative then making product positive
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[j]<0)
	                pr=pr*(-arr[j]);	//if array element is negative then making product positive
	            else
	                pr=pr*arr[j];
	            if(pr>max)	//updating Max
	                max=pr;
	        }
	    }
	    return max;
	}
};
int main() {
	//n-size of array
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) 
            cin >> arr[i];
        
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    
    return 0;
} 
