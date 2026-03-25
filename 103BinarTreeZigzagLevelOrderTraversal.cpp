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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root ==NULL){
        return result;
        }
        queue<TreeNode*> q;
        q.push(root);

        bool lefttoright= true;

        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);
            for(int i=0 ; i< size; i++){
                TreeNode * frontnode = q.front();
                q.pop();

                //normal insert or reverse insert 
                int index = lefttoright ? i: size -i-1;
                ans[index] = frontnode-> val;

                if(frontnode -> left != NULL){
                q.push(frontnode->left);
                }



                if(frontnode -> right != NULL){
                q.push(frontnode->right);
                }
                //direction cahnge karni h 
                
            }
            
            result.push_back(ans);
            lefttoright = ! lefttoright;
        }
        
        return result;
    }
};
