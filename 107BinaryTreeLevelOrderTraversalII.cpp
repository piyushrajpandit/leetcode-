```cpp
/*
LeetCode 107 - Binary Tree Level Order Traversal II

Approach: BFS (Breadth First Search) using a queue.

We traverse the tree level by level from top to bottom.
At every step, q.size() tells us how many nodes are present
in the current level, so we process exactly those nodes and
store their values in a separate vector called level.

For every node, we add its left and right children to the queue
so that they will be processed in the next level.

Normally this gives:
Root -> Level 1 -> Level 2 -> ...

But the problem wants the result from bottom to top:
Last Level -> ... -> Level 1 -> Root

Therefore, after completing BFS, we simply reverse the ans vector.

Important:
- root == nullptr -> return empty answer
- queue -> used for BFS
- q.size() -> number of nodes in the current level
- level -> stores values of one level
- reverse(ans.begin(), ans.end()) -> converts top-down to bottom-up

Time Complexity: O(n), because every node is visited once.
Space Complexity: O(n), for the queue and answer.
*/
```
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i =0 ; i< size ;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);


            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
