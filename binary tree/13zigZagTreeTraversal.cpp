 /* Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree. 

Example 1:
Input:
        3
      /   \
     2     1
Output:
3 1 2

Example 2:
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

*/

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	queue<Node*> q;
	if(!root)   return ans;
	q.push(root);
	//when flag is even we need to print the reverse level order
	int flag=1;
	while(!q.empty()){
	    //temp to store elements of current level
        vector<int> temp;
        int sz=q.size();
        while(sz--){
            Node* t=q.front();
            temp.push_back(t->data);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        //when flag is even making reverse level order
        if(flag%2==0)   reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
            ans.push_back(temp[i]);
	    flag++;
	}
	return ans;
}