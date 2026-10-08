/*
This is a very beutiful question 
here we are working in many aspect 

1.   first is maintaining index 

        1
    2      3
4     5  6     7
to maintain index we are using simple thing in left child when we move downward just do index*2 
and for right child index*2 +1 


// but by this way error has come we can take care of indexes like this so we need 
to have to indexing like 
we can do indexing as 
        0
    0  1  2  3 
0   1  2  3 4 5 6 7 

but to do this we have use current indedx


2.  now next we have to maintain level each time we move one step down we increse level +1 

3 vector for leftMost 
we save only the left most indexex here 
when we push when level == leftMost.size then we push one element so only one element get pushed on one level 


4. at last ans
ans = max( ans, int(index - leftMost[level] +1));
if means simple we just calculte left most index minus current index and we get the answer simple 


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
    int ans = 0;
    void dfs(TreeNode* root, long long index ,int level , vector<long long >& leftMost){
        if(root == nullptr){
        
            return ;
        }
        if(level == leftMost.size()){
            leftMost.push_back(index);
        }
        long long currindex = index - leftMost[level];
        ans = max(ans, (int)(currindex  +1));

        dfs(root->left, currindex*2, level +1, leftMost);
        dfs(root->right, currindex* 2 +1, level+1, leftMost);
     

    }
    int widthOfBinaryTree(TreeNode* root) {
         vector<long long >leftMost;
         dfs(root, 1, 0, leftMost);
        return ans ;
    }
};
