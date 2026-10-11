
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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> answer;
        if(root == nullptr) return answer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size =q.size();
            vector<int> level;
            for(int i =0 ; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);
            }
            long long  sum = 0;
            for(int i =0 ;i< level.size(); i++){
                sum+= level[i];
            }
            double avg = (double)sum /level.size();
            answer.push_back(avg);
        }
        return answer;
    }
};
