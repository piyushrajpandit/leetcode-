
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
    unordered_map<int , int>ans;
    int answer;
    int maxLevel =0;
    void dfs( TreeNode* root , int level){
        if(root == nullptr){
            return;
        }
        if(ans.find(level) != ans.end()){
            ans[level] += root->val;
        }
        else{
            ans[level] = root->val;
        }
        if(level > maxLevel){
            maxLevel = level;
            answer = ans[level];
        }
        else if(level == maxLevel){
            answer = ans[level];
        }

        dfs(root->left, level+1);
        dfs(root->right, level+1);

    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 1);
        return answer;
    }
};
