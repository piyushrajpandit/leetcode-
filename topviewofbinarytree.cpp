// #appraoch 
// ye wla code same hai horizontal approach ka bas apko isme ek chiz dekhna hai wo hai 
// ek bar agar mapping kar diya to dobara nahi karna hai use hd distance se 
// iska tarika hai 
// topNode.find karo (hd) agar wo nahi mila to tioNode.end return hoga



class solution {
public:

vector<int> topView(Node *root){
  vector<int> ans;
if(root == NULL){
return ans;
}
map<int,int> topNode;
queue<pair<Node , int>> q;
q.push(make_pair(root, 0));
while(!q.empty()){
pair<Node*, int> temp = q.front();
q.pop();
Node * frontNode = temp.first;
int hd = temp.second;

//if one value is present for hsd, then do nothing 
if(topNode.find(hd) == topNode.end())
  //iska matlab hao agar apne iska entey nikale aur iske find kuch nahi mila to iska output topNode.end() ke baranbar ata hai 
  topNode[hd] = frontNode->data;
if(frontNode->left)
  q.push(make_pair((frontNode->left, hd-1);
if(frontNode->right)
  q.push(make_pair(frontNode->right, hd+1);
}
for(auto i : topNode){
ans.push_back(i.second);
}
return ans;
}
    
