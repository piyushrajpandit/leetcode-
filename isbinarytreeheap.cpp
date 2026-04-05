
int countNodes(struct Node* root){
//base case 
if(root==NULL){
return 0;
int ans= 1 + countNode(root->left) + countNodes(root->right);
return ans;
}

bool isCBT(struct Node* root, int index , int cnt){
if(root == NULL)
return true;
if(index > = cnt)
return false;
else{
bool left = isCBT(root->right, 2 * index +1 , cnt);
bool right = isCBT(root->right,2*index+2, cnt);
return (left && right);

}
}
bool ismaxorder(struct Node* root){
//leaaf node 
if(root->left == NULL && root->right == NULL){
return true;
if(root->right == NULL){
return (root->data > root->left->data);
}
esle{
bool left = isMaxOrder(root->left);
bool right = isMaxOrder(root->right);
return(left && right && (root->data > root->left->data && root->data > root->right->data)){



}




bool isHeap(struct Node* root){
int index= 0;
int totalCount = countNodes(root);
if(isCBT(root,index, totalCount) && isMazOrder(root)){
return root;
}
else{
return false;
}
