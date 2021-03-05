//Write a program to find the node at which the intersection of two singly linked lists begins.
/*Example1 :
Input:listA=[4,1,8,4,5],listB=[5,6,1,8,4,5]
Output: Reference of the node with value = 8 */

/* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };  */

//Brute-Force  Approach :
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //iterating each element of 1st List and comparing it with each element of 2nd List
         while (headA != nullptr) 
         {
            ListNode *pB = headB;
            while (pB != nullptr) 
            {
                //if same elements found then return it as intersection
                if (headA == pB) 
                    return headA;
                
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
//Optimal Approach :
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;
        //iterting list 1 and 2 untill any one of them ends  
        while(a!=b)
        {
            //when list 1 end then a will iterate through list 2
            if(a==NULL)
                a=headB;
            else
                a=a->next;
            //when list 2 end then b will iterate through list 1
            if(b==NULL)
                b=headA;
            else
                b=b->next;

            //both a and b will keep iterating untill they reach same node i.e Intersection 
        }
        return a;
    }