/* Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false. */
/* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };*/

//Brute-Force Approach :
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //create hashSet to Store LL nodes:
        set <ListNode *> hashSet;
        if(head==NULL)
            return false;
        while(head->next!=0)
        {
            //if current node is not already present in hashset then add it,
	    //if it is already found in hashset then its cycle.
            if(hashSet.count(head))
                return true;
            else
                hashSet.insert(head);
            head=head->next;
        }
        return false;
    }
};

//Optimal Approach :
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;

        //create 2 pointer initially pointing head
        ListNode *fast=head,*slow=head;
        
        
        //move fast with 2 node and slow with 1 node
        //if there exist a cycle then there will be situation where fast will
        //overlap with slow
        while(fast->next  && fast->next->next)
        {
            fast=(fast->next)->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};