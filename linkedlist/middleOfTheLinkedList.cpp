/*Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.
Example 1: Input: [1,2,3,4,5]   Output: Node 3 from this list (Serialization: [3,4,5])
Example 2: Input: [1,2,3,4,5,6] Output: Node 4 from this list (Serialization: [4,5,6]) */

/*Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

//Brute Force Approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //making temperory pointer pointing head
        ListNode *temp=head;
        int c=1;    //c-count number of node
        //traversing Linked List till Last node to count no. of Nodes
        while(temp->next!=0)
        {
          c++;
          temp=temp->next;
        }
        //moving head pointer till the middle node 
        for(int i=1;i<=c/2;i++)
        {
            head=head->next;
        }
        return head;
    }
};

//Optimal Approach : Using tortoise method
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head,*fast=head;
        //slow will be increased by 1 node and fast will be increased by 2 nodes
        //so that when fast reach to last node then s low will be pointing middle node
        while(fast!=0 && fast->next!=0)
        {
            slow=slow->next;
            fast=(fast->next)->next;
        }
        return slow;
        
    }
};
