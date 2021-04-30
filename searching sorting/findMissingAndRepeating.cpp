class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        //temp-to store occurance of each element
        //as array index start with 0 hence size n+1       
        int temp[n+1]={0};
        int *ans=new int[2];

        for(int i=0;i<n;i++)
        {
            //increase occurance of of element 
            //and check if it occured 2 time
            temp[arr[i]]++;
            if(temp[arr[i]]==2)
                ans[0]=arr[i];
        }
        
        //check which element occured 0 times that is missing element
        for(int i=1;i<n+1;i++)
        {
            if(temp[i]==0)
                ans[1]=i;
        }
        return ans;
    }
};