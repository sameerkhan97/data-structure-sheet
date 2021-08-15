/*    //if a node is smaller than lower range then only search in its right subtree coz its a BST

*/

//Brute force
int getCount(Node *root, int l, int h)
{
    queue<Node *> q;
    q.push(root);
    int count=0;
    //traversing every node and comparing with l,h
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp->data>=l && temp->data<=h) count++;;
            
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return count;
}

//Optimal
int getCount(Node *root, int l, int h)
{
    if(!root)   return 0;
    //if a node fall in range then search in its both subtree
    if(root->data>=l && root->data<=h)
        return 1+getCount(root->right,l,h)+getCount(root->left,l,h);
    //if a node is smaller than l range then only search in its right subtree coz its a BST
    else if(root->data<l)
        return getCount(root->right,l,h);
    //if a node is larger than h then only search in its left subtree coz its a BST
    else  
        return getCount(root->left,l,h);
}