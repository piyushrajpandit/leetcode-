void makeSet(vector<int> &parent, vector<int> &rank, int n ){
  for(int i  =0 ; i< n ; i++){
    parent[i] = i ;
    rank[i] = 0 ;
  }
}
int findParent(vector<int> &parent, int node){
  if(parent[node] == node){
return node;
  }
return parent[node] =  findParent(parent, parent[node]);
}
int minimimSpanningTree(vector<vector<int>> & edges ,int n){
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent , rank , n);
}
