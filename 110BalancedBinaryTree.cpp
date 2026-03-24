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
    int height(struct TreeNode * root){
        if(root == NULL){
            return 0;

        }
        int left= height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        bool  left = isBalanced(root->left);
        bool  right = isBalanced(root->right);
        bool diff = abs(height(root->left)- height(root->right)) <=1;
        if(left &&right &&diff){
            return true;
        }
        else{
            return false;
        }
        
    }
};

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
    
    pair<int,int> isfastBalanced(TreeNode * root){
         if(root == NULL){
            pair<int,int> p = make_pair(true, 0);
            return p;
        }
        pair<int,int> left = isfastBalanced(root->left);
        pair<int,int> right = isfastBalanced(root->right);

        bool  leftans = left.first;
        bool  rightans = right.first;
        bool diff = abs(left.second- right.second) <=1;
        pair<bool, int> ans;
        ans.second = max(left.second,right.second) +1;
        if(leftans &&rightans &&diff){
            ans.first =  true;
        }
        else{
            ans.second = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
       
        return isfastBalanced(root).first;
    }
};
