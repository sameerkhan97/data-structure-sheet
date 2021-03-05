/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */
//CPP Code :
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //creating a dummy Node,which will store head of new LL
        ListNode *dummy=new ListNode(0,NULL);
        ListNode *temp=dummy;
        //c-will carry digit after every sum i.e 10+2=12 then c will carry 2
        int c=0,sum;
        while(l1!=NULL || l2!=NULL || c!=0)
        {
            sum=0;
            //sum values of l1,l2 untill one of then reach null
            if(l1!=NULL)
            {
                sum=sum+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum=sum+l2->val;
                l2=l2->next;
            }
            //adding carry in sum which may be from previous sum 
            sum=sum+c;
            //cheking for any carry in current sum
            c=sum/10;
            //new Node will have sum%10 ,remaining will be added through carry
            ListNode *newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
        }
        //returning dummy's  because it will be pointing to head of LL
        return dummy->next;
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //creating a dummy Node,which will store head of new LL
        ListNode dummy=new ListNode(0,null);
        ListNode temp=dummy;
        //c-will carry digit after every sum i.e 10+2=12 then c will carry 2
        int c=0,sum;
        while(l1!=null || l2!=null || c!=0)
        {
            sum=0;
            //sum values of l1,l2 untill one of then reach null
            if(l1!=null)
            {
                sum=sum+l1.val;
                l1=l1.next;
            }
            if(l2!=null)
            {
                sum=sum+l2.val;
                l2=l2.next;
            }
            //adding carry in sum which may be from previous sum 
            sum=sum+c;
            //cheking for any carry in sum
            c=sum/10;
            //new Node will have sum%10 ,remaining will be added through carry
            ListNode newNode=new ListNode(sum%10);
            temp.next=newNode;
            temp=temp.next;
        }
        //returning dummy's  because it will be pointing to head of LL
        return dummy.next;
    }
}
            
        