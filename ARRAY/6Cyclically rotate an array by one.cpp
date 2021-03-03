//Given an array, rotate the array by one position in clock-wise direction.

#include <stdio.h>
void rotate(int arr[], int n);
int main()
{
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        return 0;
}
void rotate(int arr[], int n)
{
    //storing last element of array in temp
    int temp=arr[n-1],i=0;
    int t,extra=arr[0];
    while(i<n-1)
    {
        //copying each element in its next index untill last element gets copied 
        t=arr[i+1];
        arr[i+1]=extra;
        extra=t;
        i++;
    }
    //storing last element in 1st place
    arr[0]=temp;
}
