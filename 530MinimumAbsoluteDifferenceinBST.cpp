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
    vector<int> element;
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        element.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        for(int i =0 ; i< element.size();i++){
            for(int j =i+1; j< element.size();j++){
                int diff = abs(element[i] - element[j]);
                ans = min(ans, diff);
            }
        }
        return ans;
    }
};
