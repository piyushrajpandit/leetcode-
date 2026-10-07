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
    int count = 0;
    void sumation( TreeNode* root ,int targetSum , long long sum){
        if(root == NULL) return;
        sum += root->val;
        if(sum == targetSum)    count++;
       
            sumation(root->left, targetSum, sum);
            sumation(root->right, targetSum , sum);
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0 ;
        sumation(root, targetSum , 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;

    }
};
