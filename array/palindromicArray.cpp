/*Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of 
the Array are palindrome otherwise it will return 0.
Example 1: Input:5      a[]={111 222 333 444 555}   ,   Output: 1
Explaination : A[0] = 111    //which is a palindrome number.A[1] = 222   //which is a palindrome number.A[2] = 333   //which is a palindrome number.
               A[3] = 444  //which is a palindrome number.  A[4] = 555  //which is a palindrome number.
               As all numbers are palindrome so This will return 1.

Example 2: Input:3      a[]={121 131 20}
            Output: 0  */


int PalinArray(int a[], int n)
{
    int temp,rev;
    for(int i=0;i<n;i++)
    {
        //algorithm for pallindrome check
        temp=a[i];
        rev=0;
        while(temp!=0)
        {
            rev=rev*10+(temp%10);
            temp=temp/10;
        }
        //if any element in array isnt pallindrome return 0
        if(rev!=a[i])
            return 0;
    }
    return 1;
}