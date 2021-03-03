// Q-Given a string S, check if it is palindrome or not.if yes retrun 1 otherwise 0.

#include <stdio.h>
#include <string.h>
int isPlaindrome(char S[])
{
   //use same approach as reverse just instead of swapping compare elements at start and end
    int start=0,end=strlen(S)-1;
    while(start<end){
        if(S[start]!=S[end]) //if any ent at start and end dont match then break the loop and return 0
            break;
        start++;
        end--;
    }
    if(start<end)
        return 0;
    else
        return 1;
}
int main() 
{
   		char s[100000];
   		scanf("%s", &s);;


   		printf("%d\n", isPlaindrome(s));
     return 0;
}
