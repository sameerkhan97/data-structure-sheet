//Given the head of a linked list, remove the nth node from the end of the list and return its head.
/* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        -ListNode *temp=head,*pre=NULL;
        int s=1;
        //moving temp pointer till last node to determine size of LL
        while(temp->next!=NULL)
        {
            temp=temp->next;
            s++;                //s-storing size of LL
        }
        if(s==n){               //if size==n i.e we need to remove head node
            head=head->next;
            return head;
        }
        n=s-n;
        s=0;
        temp=head;
        //iterating s-till s reaches no. of node to be deleted
        while(s<n)
        {
            pre=temp;           //pre-pointing previous node of temp
            temp=temp->next;    
            s++;
        }
        //connecting previous node with next node of deleting node i.e disconnecting deleting node
        pre->next=temp->next;
        delete temp;
        return head;
    }
};


//Java Code :
/* Definition for singly-linked list.
   public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }*/
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head,pre=null;
        int s=1;
        //moving temp pointer till last node to determine size of LL
        while(temp.next!=null)
        {
            temp=temp.next;
            s++;                //s-storing size of LL
        }
        if(s==n){               //if size==n i.e we need to remove head node
            head=head.next;
            return head;
        }
        n=s-n;
        s=0;
        temp=head;
        //iterating s-till s reaches no. of node to be deleted
        while(s<n)
        {
            pre=temp;           //pre-pointing previous node of temp
            temp=temp.next;    
            s++;
        }
        //connecting previous node with next node of deleting node i.e disconnecting deleting node
        pre.next=temp.next;
        return head;
    }
}