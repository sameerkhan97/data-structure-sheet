#include <iostream>
using namespace std;
int main() 
{
    string str="Hello"; 
    //take 2 pointers pointing 1st and last character of String
    int start=0,end=str.length()-1;
    //swap element at start & end untill start exceeds end
    while(start<end){
        char t=str[start];
        str[start]=str[end];
        str[end]=t;
        start++;
        end--;
    }
    cout<<"\n"<<str;
    return 0;
}  
