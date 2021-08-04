/* Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

Output : 1
Explanation : 
    2     
  /   \    
 4     5

is the duplicate sub-tree.
 

Example 2 :

Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree in the given binary tree.

*/

unordered_map<string,int> m;
string solve(Node *root){
    if(!root)   return "N";
    
    string s="";
    if(!root->left && !root->right){
        s=to_string(root->data);
        return s;
    }
    s=s+to_string(root->data);
    s=s+solve(root->left);
    s=s+solve(root->right);
    m[s]++;
    return s;
}
bool dupSub(Node *root)
{
    m.clear();
    solve(root);
    for( auto x:m){
        if(x.second>=2)   return true;
    }
    return false;
}