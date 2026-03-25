#appraoch 

you have to tranverse level wise so first write basic code for level order tranversal
now add sometings like lefttoright bool when it is true then only go left to right else go right to left and add valuses into query 
and run the loop this q  not became empty 
first thing take first of query and pop if from query 
now find index if left to right is there go from 0 to end else end to 0
 int index = lefttoright ? i: size -i-1;
                ans[index] = frontnode-> val;
aur fir left node dal do 
fir right node dal do 
and repeat this to this after that onces last for loop is empty then put ans in result and change leftto right to false 
and you have new query of another size do for that also

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
