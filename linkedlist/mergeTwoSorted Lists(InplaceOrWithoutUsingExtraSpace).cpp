//Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
//CPP CODE :
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



//JAVA Code :
/* Definition for singly-linked list.
   public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  } */

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null)    return l2;
        if(l2==null)    return l1;
        //l1 will point to the smaller node 
        if(l1.val>l2.val)
        {
            ListNode t=l1;
            l1=l2;
            l2=t;
        }
        //res-will keep pointer to first Node
        ListNode res=l1;
        while(l1!=null && l2!=null)
        {
            ListNode temp=null;
            //moving l1 in LL untill it points to >value that l2
            while(l1!=null && l1.val<=l2.val)
            {
                //temp will be pointing one previous node of l1
                temp=l1;
                l1=l1.next;             
            }
            //one previous node of l1 will now popint to node at l2
            temp.next=l2;
            //swap l1,l2 because l1 will always point to smaller Node
            ListNode t=l1;
            l1=l2;
            l2=t;
        }
        return res;
    }
}