/* Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list,
 instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list. */
/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        //copying the value of next node in deleting node
        //pointing deleting node to the next of next node
        //now deleting node will be pointing to next of next node and has value of next node i.e it will become next node
        //we copied both pointers and value of next node to deleting node hence all its data is deletednode->val=(node->next)->val;
        node->next=(node->next)->next;
    }
};
