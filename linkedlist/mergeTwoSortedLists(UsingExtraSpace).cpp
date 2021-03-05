// Merge two sorted linked lists and return it as a sorted list. 
//The list should be made by splicing together the nodes of the first two lists.
/* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/
 
//Sorting 2 LinkedLists and making 3rd Sorted LinkedList
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //creating first node as head to point to first Node;
        ListNode *head=new ListNode(0,NULL);
        ListNode *temp=head;    //temp-pointer to traverse new linked list
       //traversing 1st ,2nd Linked List untill one of them ends
        while(l1!=0 && l2!=0)
        {
            //comparing values at l1 & l2 and inserting smaller value in new node
            //after inserting increasing pointer to the next node
            if(l1->val<l2->val)
            {
                ListNode *newNode=new ListNode(l1->val,NULL);
                l1=l1->next;
                temp->next=newNode; //inserting newNode to 3rd Linked List
                temp=newNode;       //moving pointer to newNode
            }
            else
            {
                ListNode *newNode=new ListNode(l2->val,NULL);
                l2=l2->next;
                temp->next=newNode;
                temp=newNode;
            }
        }
        //if 2nd LL ends then copying all the remaining node of 1st LL to 3rd LL
        while(l1!=0)
        {
            ListNode *newNode=new ListNode(l1->val,NULL);
            l1=l1->next;
            temp->next=newNode;
            temp=newNode;
        }
        //if 1st LL ends then copying all the remaining node of 2nd LL to 3rd LL
        while(l2!=0)
        {
            ListNode *newNode=new ListNode(l2->val,NULL);
            l2=l2->next;
            temp->next=newNode;
            temp=newNode;
        }
        //last node will point to null
        temp->next=NULL;
      	 //returning head->next because head will contain 0 value
        return head->next;
    }
};
