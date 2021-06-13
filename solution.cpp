class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root){
            return false;
        }
        TreeNode* parent1;
        TreeNode* parent2;
        bool foundx=false;
        bool foundy=false;
        int d1=0;
        int d2=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && (!foundx||!foundy)){
            if(q.front()->left != nullptr){
                q.push(q.front()->left);
            }
            if(q.front()->right != nullptr)
                q.push(q.front()->right);
            
            if((q.front()->left!= nullptr && q.front()->left->val==x) ||(q.front()->right!= nullptr && q.front()->right->val==x)){
                parent1 = q.front();
                
                foundx=true;
            }
            
            if((q.front()->left!= nullptr && q.front()->left->val==y) ||(q.front()->right!= nullptr && q.front()->right->val==y)){
                parent2 = q.front();
                
                foundy=true;
            }
        q.pop();
            
        }
        
        d1 = findDepth(root,x);
        d2 = findDepth(root,y);

        if(parent1==parent2){
            return false;
        }
        if(d1!=d2){
            return false;
        }
        return true;
    }
    int findDepth(TreeNode* root, int x)
{
    // Base case
    if (root == NULL)
        return -1;
 
    // Initialize distance as -1
    int dist = -1;
 
    // Check if x is current node=
    if ((root->val == x)
 
        // Otherwise, check if x is
        // present in the left subtree
        || (dist = findDepth(root->left, x)) >= 0
 
        // Otherwise, check if x is
        // present in the right subtree
        || (dist = findDepth(root->right, x)) >= 0)
 
        // Return depth of the node
        return dist + 1;
 
    return dist;
}

};
