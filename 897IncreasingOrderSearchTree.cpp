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
    void inorder(TreeNode* root,vector <int>& in){
        if(root==NULL){
            return ;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* increasingBST(TreeNode* root) {
        //store in inorder
        vector<int> in;
        inorder(root,in);
        int n= in.size();
        TreeNode * newroot = new TreeNode(in[0]);
        TreeNode * curr =  newroot;
        //2nd step 
        for(int i =1; i< n;i++){
            TreeNode* temp = new TreeNode (in[i]);
            curr->left = NULL;
            curr->right =temp;
            curr =temp;
        }
        //3rd step 
        curr->right = NULL;
        curr->left = NULL;

        return newroot;
    }
};
