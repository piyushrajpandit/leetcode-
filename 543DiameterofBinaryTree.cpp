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
time complexity o(n^2);
class Solution {
public:
int height(struct TreeNode* node){
  if(node ==NULL){
return 0;
  }
    int left = height(node->left);
int right = height(node->right);
int ans = max(left, right) +1;
return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
      if(root == NULL){
return 0;
  }
int op1 = diameterOfBinaryTree(root->left);
int op2 = diameterOfBinaryTree(root->right);
int op3 = height(root->left) + height(root->right) ;
int ans = max(op1, max(op2, op3));
return ans;   
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

this is optimized code 
class Solution {
public:
pair<int , int> daimeterFast(TreeNode* root){
    if(root == NULL){
    pair<int,int> p = make_pair(0,0);
        return p;
        }
        pair <int, int> left = daimeterFast(root->left);
        pair<int, int> right = daimeterFast(root-> right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second  ;

        pair<int, int> ans;
        ans.first =  max(op1, max(op2, op3));
        ans.second = max(left.second , right.second) +1 ;
        
        return ans;  
        }

    int diameterOfBinaryTree(TreeNode* root) {
         return daimeterFast(root).first;  
    }
};
