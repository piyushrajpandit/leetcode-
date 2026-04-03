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
vector<int> merger(vector<int> a,vector<int> b){
    vector<int> ans( a.size() + b.size());
    int i=0; 
    int j=0;
    int k = 0;
    while(i < a.size() && j <  b.size()){
        if(a[i] < b[j]){
            ans[k++]= a[i];
            i++;
        }
        else{
            ans[k++]= b[j];
            j++;
        }
        
    }
    while(i < a.size()){
        ans[k++]= a[i];
        i++;
    }
    while(j < b.size()){
        ans[k++]= b[j];
        j++;
    }
    return ans;
}
void inOrder(TreeNode* root1, vector<int> &in){
    if(root == NULL){
        return NULL;
    }
    inOrder(root->left, in);
    in.push_back(root->val);
    inOrder(root->right, in);
}
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //step 1 : store inorder 
        vector<int> bst1, bst2;
        inOrder(root1, bst1);
        inOrder(root2, bst2);

        vector<int> mergeArray = merger(bst1, bst2);
        return mergeArray
    }
};
