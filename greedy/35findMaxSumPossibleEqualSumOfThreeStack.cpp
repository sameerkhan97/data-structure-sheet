/*Given three stacks of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements
  allowed. Stacks are represented as an array, and the first index of the array represent the top element of the stack.
  
Examples: 
Input : stack1[] = { 3, 10} , stack2[] = { 4, 5 } , stack3[] = { 2, 1 }
Output : 0

Sum can only be equal after removing all elements from all stacks.  */

#include <iostream>
using namespace std;

int main() {
	int stack1[] = { 3, 2, 1, 1, 1 };
    int stack2[] = { 4, 3, 2 };
    int stack3[] = { 1, 1, 4, 1 };
	
	int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);
    
    
    int sum1=0,sum2=0,sum3=0;
    for(int i=0;i<n1;i++)
    	sum1+=stack1[i];
    for(int i=0;i<n2;i++)
    	sum2+=stack2[i];
    for(int i=0;i<n3;i++)
    	sum3+=stack3[i];
    
    int top1=0,top2=0,top3=0;
    
    
    while(1){
    	if(top1==n1 || top2==n2 ||top3==n3){
    		cout<<"0";
    		break;
    	}
    	if(sum1==sum2 && sum2==sum3){
    		cout<<sum1;
    		break;
    	}
    	if(sum1>=sum2 && sum1>=sum3)
    		sum1=sum1-stack1[top1++];
    	else if(sum2>=sum1 && sum2>=sum3)
    		sum2=sum2-stack2[top2++];
    	else if(sum3>=sum1 && sum3>=sum2)
    		sum3=sum3-stack3[top3++];
   
    }
}