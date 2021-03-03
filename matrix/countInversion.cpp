/ *Given an array of integers. Find the Inversion Count in the array. 
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
Example 1: Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3). */
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long inversionCount(long long arr[],long long N)
    {
       long long invCount=mergeSort(arr,0,N-1);
        return invCount;
    }
    long long mergeSort(long long *a,long long l,long long u)
    {
        long long mid,invCount=0;
        if(l<u)
        {
            mid=(l+u)/2;
            invCount=invCount+mergeSort(a,l,mid);
            invCount=invCount+mergeSort(a,mid+1,u);
            invCount=invCount+merge(a,l,mid+1,u);
        }
        return invCount;
    }
    long long merge(long long *a,long long l,long long mid,long long u)
    {
        long long b[u+1],i=l,j=mid,k=l,invCount=0;
        while(i<=mid-1 && j<=u)
        {
            if(a[i]<=a[j])
                b[k++]=a[i++];
            else{
                b[k++]=a[j++];
                invCount=invCount+(mid-i);
            }
        }
        while(i<=mid-1)
            b[k++]=a[i++];
    
        while(j<=u)
            b[k++]=a[j++];
        
        for(k=l;k<=u;k++)
            a[k]=b[k];
            
        return invCount;
    }
};
int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
