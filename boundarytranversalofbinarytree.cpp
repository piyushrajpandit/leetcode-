// 3 things we have to do 

// 1. left wala part kara lo (leaf node print mat karana)
// 2. sirf leaf node print karan 
// 3. right part print kara do (leaf node print mat karna)
//  right reverse direction me print karna hai 

class Solution {
public:
 void transverseLeft(Node * root, vector<int> &ans){
   //base case 
   if((root == NULL) || (root->left == NULL && root->right == NULL))
     return ;

   ans.push_back(root->data);
   if(root->left)
     traverseLeft(root->left,ans);
    else(root->right);
   traverseLeft(root->right,ans);
   

 }


void traversLeaf(Node * root, vector<int> &ans){
  //base case
  if(root == NULL){
    return ;
  }
  if(root->left == NULL && root->right == NULL){
    ans.push_back(root->data);
    return ;
  }
  tranverseLeaf(root->left,ans);
  tranverseLeaf(root->right, ans);
}
void traverseRight(NOde * root , vector<int> &ans){
//base case 
  if((root == NULL) || (root-> left ==NULL && root->right == NULL){
    return;
  }
  if(root->right){
    traverseRight(root->right,ans);
  }
  else{
    traveseLeft(root->right,ans);
  }


}
vector<int> boundary(Node *root)
{
  vector<int> ans;
  if(root ==NULL){
    return ans;
    
}
  ans.push_back(root->data);
  //left part print /store
  traverseLeft(root->left, ans);

  //traverse leaf nodes
  // left subtree
  traverseLeaf(root->left, ans);
  
  // right subtree
  traverseLeaf(root->left, ans);


  //traverse right part 
  traverseRight(root->right, ans);
  return ans ;
}

};
