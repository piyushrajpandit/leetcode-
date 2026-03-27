// actually what are we doning here we are finding ancestor here 
// so root data match with node we have we will return root 
// if not find left ans and same for right aswer 
// and we if leftans we get node and right null we will do k -- and if at any place k becomes 0 or less than 0 we will make k = int max so k never became 0 again and return the root 

// and if ans = nULL or ans data == node then means(already top node hai) no ancestor return null
// else return ans->data


Node* solve(Node* root, int &k , int node){
//base case 
if(root == NULL)
return NULL:

if(root->data == node){
return root;
}
Node * leftAns = solve(root->left, k , node);
Node * rightAns = solve(root->right, k , node );

//wapas
if(leftAns!= NULL && rightAns == NULL){
k--;
if(k<=0){
//ans lock
k= INT_MAX;
return root ;

}
return LeftAns;
}
if(leftAns == NULL && rightAns != NULL){
k--;
if(k<=0){
//ans lock
k = INT_MAX;
return root;
}
return rightAns;
}
return NULL;
}
int kthAncestor(Node * root, int k, int node){
Node* ans = solve(root, k , node);
if(ans==NULL || ans->data == node )
return -1;
else
return ans->data;
}


