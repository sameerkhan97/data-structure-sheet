/*Given the head of a linked list,rotate the list to the right by k places.
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3] */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //edge cases
        if(head==NULL || head->next==NULL || k==0)
            return head;
        
        ListNode *temp=head;
        ListNode *pre=NULL;
        int s=1;
        //compute length of LL
            while(temp->next!=NULL)
            {  
                ++s;
                temp=temp->next;
            }
            temp->next=head;
            k=k%s;
            k=s-k;
            //go till the node of rotation
            while(k!=0)
            {
                temp=temp->next;
                    k--;
            }
            //make node head and break connection
            head=temp->next;
            temp->next=NULL;
        return head;
    }
};
