// Q-Given a string S, check if it is palindrome or not.if yes retrun 1 otherwise 0.

#include <stdio.h>
#include <string.h>


 // } Driver Code Ends


//User function Template for C

int isPlaindrome(char S[])
{
    int start=0,end=strlen(S)-1;
    while(start<end){
        if(S[start]!=S[end])
            break;
        start++;
        end--;
    }
    if(start<end)
        return 0;
    else
        return 1;
}

// { Driver Code Starts.

int main() 
{
   	int t;
   	scanf("%d", &t);
   	while(t--)
   	{
   		char s[100000];
   		scanf("%s", &s);;


   		printf("%d\n", isPlaindrome(s));
   	}

    return 0;
}  // } Driver Code Ends