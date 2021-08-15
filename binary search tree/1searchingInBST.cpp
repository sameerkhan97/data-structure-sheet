/* we’ll start at the root, and then we will compare the value to be searched with the value of the root if it’s equal we are done with the
   search if it’s lesser we know that we need to go to the left subtree because in a binary search tree all the elements in the left subtree
   are lesser and all the elements in the right subtree are greater
*/

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}