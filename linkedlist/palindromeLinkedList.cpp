//Given the head of a singly linked list, return true if it is a palindrome.
/* Definition for singly-linked list.
   struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };*/

//Brute Force Approach :
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return false;
        //creating a vector and copying all linked list data in vector
        vector<int> v;
        while(head!=NULL)
        {
           v.push_back(head->val);
            head=head->next;           
        }
        //checking if data in the vector is pallindrome or not
        int start=0,end=v.size()-1;
        while(start<end)
        {
            if(v[start++]!=v[end--])
                return false;
        }
        return true;
    }
};

//Optimal Approach :
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //if LL has 0/only 1 node
        if(head->next==NULL || head==NULL)
            return true;
        ListNode *slow=head,*fast=head;
        //find middle of the linked List
        while(fast->next!=NULL && (fast->next)->next!=NULL)
        {
            fast=(fast->next)->next;
            slow=slow->next;
        }
        //reverse the right half
        slow->next=reverseList(slow->next);
        
        //move slow to the right half
        slow=slow->next;
       
        //check if left half and right half are equal or not
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        //temp-traverse in linked list,prev-point-previous node of temp
	    //nex-point next node of temp
	    ListNode *temp=head,*prev=0,*nex=head;  
        //traversing all nodes using temp
	    //revrsing them by inserting prev node's address in their next variable
	    while(nex!=0)
        {
            nex=nex->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }
	    //pointing head to last node i.e reverse list's first node
        head=prev;
        return head;
    }
};