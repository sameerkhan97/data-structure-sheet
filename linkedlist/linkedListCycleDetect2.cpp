//Given a linked list, return the node where the cycle begins. If there is no cycle, return null
/* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };*/

  //Brute Force Approach :
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //hashSet to store every node of LL.
        set<ListNode *> hashSet;
        if(head==NULL)
            return NULL;    
        while(head!=NULL)
        {
            //if current node is not present in hashSet then insert it
            //else if it is already present then its the cycle node
            if(!hashSet.count(head)){
                hashSet.insert(head);
                head=head->next;
            }
            else
                return head;
        }
        return  NULL;
    }
};

//Optimal Approach :

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;    
        //taking three pointers initially pointing head
        ListNode *slow=head,*fast=head,*entry=head;
        while(fast->next!=NULL && (fast->next)->next!=NULL)
        {
            //move slow by 1 node and fast by 2 node
            //if there is aa cycle in LL then slow and fast must collide
            slow=slow->next;
            fast=(fast->next)->next;
            if(fast==slow)
            {
                //the moment slow and fast collide we will start moving entry by 1 node from head ,and moving slow by 1 node
                //the node on which slow and entry collide will be the starting point of cycle
                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return  NULL;
    }
};
