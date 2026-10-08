/*
this the code in which we have to do save treenode and its depth 
so first we find the depth of left child and then the second child 

now the next thing is that if left child and right are same then return its root 
else we have to return the left one 
else reutrn the right one 


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    
    pair<TreeNode* , int> dfs(TreeNode* root){
        if(root == nullptr)
            return {nullptr, 0};
            auto left = dfs(root->left);
            auto right = dfs(root->right);

            if(left.second == right.second){
                return {root, left.second+1};
            }
            if(left.second > right.second){
                return {left.first, left.second+1};

            }
            return {right.first, right.second+1};
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};wwe
