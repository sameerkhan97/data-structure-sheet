#include <iostream>
using namespace std;
int main() 
{
    string str="Hello"; 
    int start=0,end=str.length()-1;
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