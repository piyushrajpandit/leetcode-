void solve(Node* root, vector<int> &ans, int level){
  //base case
if(root == NULL)
  return ;
if(level == ans.size())
  ans.push_back(root->data);

solve(root->left, ans, level+1);
solve(root->roght, ans, level+1);
}
vecotr <int> leftView(Node * root){
  vector<int>ans;
  solve(root,ans,0);
  return ans;
}
