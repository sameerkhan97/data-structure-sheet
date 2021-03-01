/* Q-Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.
Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union */
#include <bits/stdc++.h>
using namespace std;

int doUnion(int *, int , int *, int);

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	   
	    cout << doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}// } Driver Code Ends


//User function template in C++

// a and b : given array with n and m size respectively

int doUnion(int a[], int n, int b[], int m)  {
    int un[m+n],u=0,i,j,c;
    for(j=0;j<n;j++)
    {
        c=0;
        for(i=0;i<u;i++)
        {
            if(a[j]==un[i]){
                c++;
                break;
            }
        }
        if(c==0)
            un[u++]=a[j];
    }
    for(j=0;j<m;j++)
    {
        c=0;
        for(i=0;i<u;i++)
        {
            if(b[j]==un[i]){
                c++;
                break;
            }
        }
        if(c==0)
            un[u++]=b[j];
    }
    return u;
}