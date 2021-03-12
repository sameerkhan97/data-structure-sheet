//Given the head of a linked list,  remove the nth node from the end of the list and return its head.
//Optimal Approach :
/* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  }; */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       //creating dummy node to point head node
        ListNode *temp=new ListNode();
        temp->next=head;
        //pointer slow and fast will point dummy node initially
        ListNode *slow=temp,*fast=temp;
        //if LL has 1 element then return null
        if(head->next==NULL)
            return head->next;
        //moving head by one node n times in LL 
        for(int i=0;i<n;i++)
            fast=fast->next;
        //moving fast from nth node & slow from dummy node till fast reaches last node 
        while(fast->next!=NULL)
         {
            slow=slow->next;
            fast=fast->next;
        }
        //when fast reaches last node
        //then slow will point 1 previous of nth node
        slow->next=(slow->next)->next;
        
        return temp->next;
    }
};
