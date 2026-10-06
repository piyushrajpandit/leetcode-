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
        vector<string> ans;
    void tranverse( TreeNode* root, string path){
        path += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
            return ;
        }
        if(root->left != nullptr){
            tranverse(root->left , path + "->");
        }
        if(root->right != nullptr){
            tranverse(root->right, path + "->");
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return ans;

        tranverse(root,"");
        return ans;

    }
};
