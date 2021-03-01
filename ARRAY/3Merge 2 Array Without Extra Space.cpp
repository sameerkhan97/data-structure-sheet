/* Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first */
//using gap method 
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        int nextGap(int gap)
        {
             if(gap <= 1)
                return 0;
            return (gap/2)+(gap%2);
        }     
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i,j,gap=m+n;
            for(gap=nextGap(gap);gap>0;gap=nextGap(gap))
            {
                for(i=0;i+gap<n;i++)
                {
                    if(arr1[i]>arr1[i+gap])
                        swap(arr1[i],arr1[i+gap]);
                }
                for(j=gap>n?gap-n:0;i<n && j<m;i++,j++)
                {
                    if(arr1[i]>arr2[j])
                        swap(arr1[i],arr2[j]);
                }
                if(j<m)
                {
                    for(j=0;j+gap<m;j++)
                    {
                        if(arr2[j]>arr2[j+gap])
                            swap(arr2[j],arr2[j+gap]);
                    }
                }
            }
        }
        void swap(long long &a,long long &b)
        {
            long long t=a;
            a=b;
            b=t;
        }
};

// { Driver Code Starts.

int main() 
{ 
	
        int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;


	return 0; 
} 