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
int findposition(vector<int>& inorder, int element){
    for(int i =0 ; i< inorder.size(); i++){
        if(inorder[i] == element)
        return i ;
    }
    return -1 ;
}
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& index, int inorderStart, int inorderEnd,int n){
        if(index> n || inorderStart> inorderEnd){
            return NULL;
        }
    int element = preorder[index++];
    TreeNode* root=new TreeNode(element);
    int position = findposition(inorder, element);

    root->left = solve(preorder, inorder ,index, inorderStart, position-1,n) ;
    root->right = solve(preorder, inorder, index , position+1, inorderEnd,n);
    return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0 ;
        int n = preorder.size();
        TreeNode * ans = solve(preorder,inorder, preOrderIndex,0,n-1,n);
        return ans;
    }
};
