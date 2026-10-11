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
    int ans = -1;
    void smallest (int temp, TreeNode* root){
        if(root == nullptr){
            return ;
        }
        if(root->val > temp){
            if(ans == -1 || root->val < ans){
                ans = root->val;
            }
            return ;
        }
        smallest(temp, root->left);
        smallest(temp, root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int temp = root->val;
        smallest(temp, root);
        return ans;
    }
};
