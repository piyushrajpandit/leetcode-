/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*>&        nodeToParent){
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == target)
                res = front;

            if(front->left){
                nodeToParent[front->left] = front;  // ✅ typo fixed
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;  // ✅ return added
    }

    vector<int> burnTree(TreeNode* root, map<TreeNode*, TreeNode*>& nodeToParent, int k){
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        int ans =0;
        vector<int> result;

        if(k == 0) return {root->val};

        while(!q.empty()){
            bool flag = 0;
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){  // ✅ ) fixed
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                    if(ans == k-1 ){
                        result.push_back(front->left->val);
                    }
                }
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                    if(ans == k -1){
                        result.push_back(front->right->val);
                    }
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){  // ✅
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                    if(ans == k-1 ){
                        result.push_back(nodeToParent[front]->val);
                    }
                }
            }

            if(flag == 1 ) ans++;
        }
        return result;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createParentMapping(root, target->val, nodeToParent);
        vector<int> ans = burnTree(targetNode, nodeToParent,k); 
        return ans;
    }
};




   
