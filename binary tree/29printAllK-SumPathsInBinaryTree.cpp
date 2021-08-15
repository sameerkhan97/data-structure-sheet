/*A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
  A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and 
  negative numbers can also be there in the tree.

Examples: 
 

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5  
*/


void printNodes(int x,vector<int>& path){
    for(int j=x;j<path.size();j++){
        cout<<path[j]<<" ";
    }
    cout<<"\n";
}

void solve(Node *root,vector<int>& path,int k){
    if(!root)   return;
    //add current node to path
    path.push_back(root->data);
    //checking for k-sum path in left subtree
    solve(root->left,path,k);
    //checking for k-sum path in right subtree
    solve(root->right,path,k);

    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too  
    int sum=0;
    for(int j=path.size()-1;j>=0;j--){
            sum+=path[j];
            if(sum==k){
                printNodes(j,path);
            }
    } 
    // Remove the current element from the path
    path.pop_back();
}

void printKPath(Node *root, int k){
    vector<int> path;
    solve(root,path,k);
}