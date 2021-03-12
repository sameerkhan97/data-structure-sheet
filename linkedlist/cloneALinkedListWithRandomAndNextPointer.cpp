/*A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, 
or null.Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set 
to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list 
such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to
 nodes in the original list.
Example 1 :
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]
*/
//Optimal Approach :
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter=head,*front=head;
        
        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while(iter!=NULL)
        {
            front =iter->next;
            Node *copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        
        // Second round: assign  random pointers for the copy nodes.
        iter=head;
        while(iter!=NULL)
        {
            if((iter->random)!=NULL)
                (iter->next)->random=(iter->random)->next;
            iter=(iter->next)->next;  
        }
        
        // Third round: restore the original list, and extract the copy list.
        iter=head;
        Node *dummy=new Node(0);
        Node *temp=dummy;
        while(iter!=NULL)
        {
            front=(iter->next)->next;
            
             // extract the copy
            temp->next=iter->next;
            
             // restore the original list
            iter->next=front;
            temp=temp->next;
            iter=front;
        }
        return dummy->next;
    }
};
