/* Given a Binary Search Tree. The task is to find the minimum element in this given BST.
    Example 1:
    Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
    Output: 1

    Example 2:
    Input:
             9
              \
               10
                \
                 11
    Output: 9           */
int minValue(Node* root)
{
    while(root->left)
        root=root->left;
    return root->data;
}