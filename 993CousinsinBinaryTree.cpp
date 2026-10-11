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
    pair<TreeNode* , int> find(TreeNode* root, int x, int level){
        if(root == nullptr){
            return {nullptr, -1};
        }
        if(root->left != nullptr && root->left->val == x){
            return{ root, level+1 };
        }
        if(root->right != nullptr && root->right->val == x){
            return { root, level+1};
        }
        auto left = find(root->left , x, level+1);
        if(left.first != nullptr){
            return left;
        }
       
        return find(root->right, x, level+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        auto temp1= find(root, x, 1);
        auto temp2 = find(root, y, 1);
        return temp1.second == temp2.second && temp1.first != temp2.first;
    }
};
