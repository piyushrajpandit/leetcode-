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
    unordered_map<int, int> freq;
    int postorder(TreeNode* root){
        if(root == nullptr) return 0 ;
        int leftSum  = postorder(root->left);
        int rightSum = postorder(root->right);
        int sum = root->val + leftSum + rightSum;
        freq[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder(root);
        int maxFreq = 0;

        for(auto it : freq){
            maxFreq = max(maxFreq, it.second);
        }
        vector<int>ans;
        for(auto it: freq){
            if(it.second == maxFreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
