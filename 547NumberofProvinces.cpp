// # we have done this by kruskal agorithm 
// here we need to make three functions 

// make set here we make set 
// we will provide parent , rank and , n
//   start parent [i] = i ; intilaly each node is its own parent 
// and rank of all is 0 

//   now union set 
// we have two number u and v 
// and we have to find their parent 
// and then if rank[u] < rank[v] we will make parent[u] = v 
// and so same in oppsisre case and else make parent[v] = u and increase rank of u 

// next function is find parent 
// we will find the parent if parent[node] = = node means it is parent of it self 
// if 0 <- 1 <- 2 <- 3 is the case and you want to find the parent of 3 it should return 0 so we have parent[node] =
// findParent(parent, parent[node]);

// findCircleNum this is the main function 
// isConnected[i][j] = 1 its this means it is connected city i is connnected to city j 
// and if you have two sets find their parent if they are not same then make their union 

// and at last count the number of node whose parent is same as it 





class Solution {
public:


void makeSet(vector<int> &parent, vector<int> &rank, int n ){
  for(int i  =0 ; i< n ; i++){
    parent[i] = i ;
    rank[i] = 0 ;
  }
}
void unoinSet(int u, int v , vector<int> &parent, vector<int> &rank){
    u = findParent(parent , u );
    v = findParent(parent ,v );
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u ;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int findParent(vector<int> &parent, int node){
  if(parent[node] == node){
return node;
  }
return parent[node] =  findParent(parent, parent[node]);
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);




      
        vector<int> rank(n);
         makeSet(parent , rank , n);

         //traverse matrix 
         for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(isConnected[i][j]==1){
                    int u= findParent(parent, i ); 
                    int v = findParent(parent, j);
                
                if(u!= v){
                    unoinSet(u,v, parent, rank);
                }
            }
            }
         }
            //count provinces 
            int count = 0 ;
            for(int i =0 ; i< n ; i++){
                if(parent[i]== i ){
                    count++;

                }
            }
            return count ;

         
    }
};
