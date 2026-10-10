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

    TreeNode* createBst(vector<int> & nums, int start , int end){
        if(start > end){
            return nullptr;
        }
        int middle = start + (end - start)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        TreeNode* leftchild =createBst(nums, start , middle-1);
        TreeNode* rightchild = createBst(nums, middle+1, end);
        root->left = leftchild;

        root->right = rightchild;
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBst(nums,0 , nums.size()-1);
    }
};
