/* Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
Find these two numbers. */
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n)
    {
       int c,i=1;
       int *a=new int[2];
       
       while(i<=n)
       {
           c=0;
           for(int j=0;j<n;j++)
           {
               if(arr[j]==i)
                    c++;
           }
           if(c==2)
                a[0]=i;
                
            else if(c==0)
                a[1]=i;
            
            i++;
       }
       return a;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}