```cpp
/*
LeetCode 226 - Invert Binary Tree

Approach: BFS (Breadth First Search) using a queue.

The goal is to mirror the binary tree by swapping the left and
right child of every node.

First, if root is NULL, return it because there is nothing to invert.

Put the root into a queue and process every node one by one.
For each node, swap its left and right children using a temporary
pointer. The temporary pointer is necessary because after changing
root->left, the original left child would otherwise be lost.

After swapping, add the new left and right children to the queue
so that every node in the tree is processed.

Example:
        4
       / \
      2   7

After swapping:
        4
       / \
      7   2

Important:
- Queue is used for BFS.
- Every node is visited exactly once.
- Use a temporary pointer while swapping two child pointers.
- If root == NULL, return immediately.

Time Complexity: O(n), because every node is visited once.
Space Complexity: O(n), for the queue in the worst case.
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
    void invert(TreeNode* root){
        if(root == nullptr) return ;
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i =0 ; i< size; i++){
                TreeNode* node = q.front();
                q.pop();
                invert(node);

                if(node->left != nullptr)
                    q.push(node->left);
                if(node-> right != nullptr)
                    q.push(node->right);
            }
        }
        return root;
    }
};
