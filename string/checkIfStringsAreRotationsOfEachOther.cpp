/* Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false) */
# include<iostream> 
using namespace std; 
  
/* Function checks if passed strings (str1 
   and str2) are rotations of each other */
bool areRotations(string str1, string str2) 
{ 
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length()) 
        return false; 
  //make a 3rd string by concatinating 1 two times 
   string temp = str1 + str1;  
  //if str2 is rotation of str1 then str2 must be a substring of concatinated string
  return (temp.find(str2) != string::npos); 
} 
int main() 
{ 
   string str1 = "AACD", str2 = "ACDA"; 
   if (areRotations(str1, str2)) 
     printf("Strings are rotations of each other"); 
   else
      printf("Strings are not rotations of each other"); 
   return 0; 
} 
