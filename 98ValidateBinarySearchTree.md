#approach
 1. ypu have to use recurssion
 2. first base case is if its null return treu
 3. if root->val > min && root->val <max
 4. after this call for left and right part both
 5.       bool left = isinRange(root->left, min, root->val);
            bool right= isinRange(root->right, root->val, max);
