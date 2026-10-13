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
    int answer = 0;
  
    vector<int> postorder(TreeNode *root ){
        if(root == nullptr){
            return {1, INT_MAX, INT_MIN, 0};

        }
        vector<int> left = postorder(root->left);
        vector<int> right = postorder(root->right);
        
        if(left[0] && right[0] && left[2] < root->val && root->val < right[1]){
            int sum = left[3] + right[3] + root->val;
            answer = max(answer, sum);
        
        return { 
            1, 
            min(left[1] , root->val),
            max(right[2] , root->val),
            sum
        };
    }
    return {0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return answer;
    }
};
