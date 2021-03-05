// Given the head of a singly linked list, reverse the list, and return the reversed list.

/*Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };*/

class Solution {
public:
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