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
    unordered_map<int ,int> freq;
    void dfs(TreeNode* root){
        if(root== nullptr){
            return ;
        }
        freq[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        int maxi= 0;
        for(auto temp: freq ){
            int times = temp.second;
            if(times == maxi){
                ans.push_back(temp.first);
            }
            if(times > maxi){
                ans.clear();
                maxi = temp.second;
                ans.push_back(temp.first);
            }
        }
        return ans;
    }
};
