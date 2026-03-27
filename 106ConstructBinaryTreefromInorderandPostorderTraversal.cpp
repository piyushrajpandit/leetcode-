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
    void createmapping( vector<int> inorder,map<int ,int> &nodeToindex, int n ){
        for(int i =0 ; i< n; i++){
            nodeToindex[inorder[i]]=i;

        }
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& index, int inorderStart, int inorderEnd,int n,map<int, int>& nodeToindex){
        if(index < 0 || inorderStart> inorderEnd){
            return NULL;
        }
    int element = postorder[index--];
    TreeNode* root=new TreeNode(element);
    int position = nodeToindex[element];

    root->right = solve(postorder, inorder, index , position+1, inorderEnd,n,nodeToindex);
    root->left = solve(postorder, inorder ,index, inorderStart, position-1,n,nodeToindex) ;
    return root;


    }
 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1 ;
        map<int, int> nodeToindex ;
        createmapping(inorder, nodeToindex, n);
     
        TreeNode * ans = solve(postorder,inorder, postOrderIndex,0,n-1,n,nodeToindex);
        return ans;
    }
};
