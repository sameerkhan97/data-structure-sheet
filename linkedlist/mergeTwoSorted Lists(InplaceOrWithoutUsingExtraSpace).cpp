//Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        //l1 will point to the smaller node 
        if(l1->val>l2->val)
            std::swap(l1,l2);
        
        //res-will keep pointer to first Node
        ListNode *res=l1;
        //moving l1 in LL untill it points to a value > l2
        while(l1!=NULL && l2!=NULL)
        {
            ListNode *temp=NULL;
            while(l1!=NULL && l1->val<=l2->val)
            {
                temp=l1;
                l1=l1->next;
            }
            //one previous node of l1 will now popint to node at l2
            temp->next=l2;
            //swap l1,l2 because l1 will always point to smaller Node
            std::swap(l1,l2);
        }
        return res;
    }
};
