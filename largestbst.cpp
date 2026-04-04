// 4 things max min isbst and size 
// so you have to return four things every time 
// how to check valid bst 
// left true hon achiye roght true and it should be greater than left max and less than right min 

class info{
public:
int maxi;
int mini;
bool isBST;
int size;
};
info solve(TreeNOde<int>* root ,int &ans){
//base case 
if(root== NULL){
return (INT_MIN,INT_MAX, true, 0);
}
info left =solve(root->left, ans);
info right = solve(root->right, ans);
int curNode;
currNode.size = left.size + right.size +1;
currNode.maxi = max(root->data , right.maxi);
currNode.mini = min(root->data, left.mini);
if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.min){
currNode.isBST = true;
esle{
currNode.isBST = false;
}
//answer update 
if(currNode.isBST){
ans= max(ans,currNode.size);
}
return currNode;
}


int largestBst(TreeNode<int>* root){
in maxSize= 0;
info temp = solve(root, maxSize);
return maxSize;
}
