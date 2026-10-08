/*
    FULL BINARY TREE (LeetCode 894) - REVISION SUMMARY

    Goal:
    Generate all possible Full Binary Trees with exactly n nodes.
    A Full Binary Tree means every node has either 0 or 2 children.

    Key observations:
    1. A Full Binary Tree can only have an ODD number of nodes.
       -> If n is even, return empty.

    2. Base case:
       -> If n == 1, only one tree is possible: a single root node.

    3. For every possible odd number of nodes for the left subtree:
       leftNodes = 1, 3, 5, ...
       rightNodes = n - 1 - leftNodes

       The "-1" is for the root node.

    4. Recursively generate:
       -> All possible left trees using leftNodes.
       -> All possible right trees using rightNodes.

    5. Combine every left tree with every right tree:
       -> Create a new root.
       -> Attach one left tree and one right tree.
       -> Store this tree in answer.

    6. Return all generated trees.

    IMPORTANT IDEA:
    We divide the n nodes as:

             root (1)
            /       \
       leftNodes   rightNodes

    Since both subtrees must also be Full Binary Trees,
    both leftNodes and rightNodes must be odd.

    Example: n = 7

        left = 1, right = 5
        left = 3, right = 3
        left = 5, right = 1

    For each split, combine every possible left tree
    with every possible right tree.

    CORE PATTERN TO REMEMBER:
    "Choose every valid left subtree size -> recursively build
     left/right trees -> combine every pair."

    Time/space:
    The number of possible Full Binary Trees grows exponentially,
    so the output itself is very large. The recursion generates
    exactly all valid tree structures.
*/
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
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> answer;
        if( n%2 == 0)
            return answer;

        if(n == 1 ){
            answer.push_back(new TreeNode(0));
            return answer;
        } 
        for(int leftNodes =1 ;leftNodes < n; leftNodes += 2){
            int rightNodes = n -1- leftNodes;

            vector<TreeNode*> leftTrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightTrees = allPossibleFBT(rightNodes);

            for(TreeNode* left : leftTrees){
                for(TreeNode* right : rightTrees){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    answer.push_back(root);
                }
            } 
        }
        return answer;
    }
}; 
