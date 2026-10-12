


/*
LeetCode 669: Trim a BST

- If root is NULL, return NULL.
- If root->val < low, trim the right subtree.
- If root->val > high, trim the left subtree.
- Otherwise, trim both left and right subtrees.
- Reconnect the trimmed subtrees and return root.

Intuition: Use BST property to discard invalid subtrees.
Time: O(n), Space: O(h).
*/





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
 
  
    TreeNode* trimBST(TreeNode* root, int low, int high) {
          if(root == nullptr){
            return nullptr;
        }
        if(root->val < low  ){
            return trimBST(root->right, low, high);
        }
        if(root->val > high  ){
            return trimBST(root->left, low, high);
        }
        TreeNode* left = trimBST(root->left, low, high);
        TreeNode* right = trimBST(root->right, low , high);

        root->left = left;
        root->right = right;
        return root;
    }
};
