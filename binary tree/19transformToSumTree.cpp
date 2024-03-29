/*Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains
  the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:
Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:
           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right  subtrees in the original tree
    int solve(Node * root) {
      if (!root) return 0;
      //first traversing in in left subtree
      int left = solve(root -> left);
      //then right child
      int right = solve(root -> right);
      //storing curr root data
      int x = root -> data;
      //now changing current root data to sum of left & right child node
      root -> data = left + right;

      //returning new root data + old root data
      return root -> data + x;
    }
  void toSumTree(Node * node) {
    solve(node);
  }
};