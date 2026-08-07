// Maintain two separate DSUs:
// - Alice's graph (type 1 + type 3 edges)
// - Bob's graph (type 2 + type 3 edges)

// Process all type 3 edges first since they benefit both Alice and Bob.
// Keep the edge if it connects new components in either DSU;
// otherwise it is redundant and can be removed.

// Process all type 2 edges for Bob.
// Keep only edges that connect different components;
// otherwise count them as removable.

// Process all type 1 edges for Alice.
// Keep only edges that connect different components;
// otherwise count them as removable.

// Track the number of connected components for Alice and Bob.
// Every successful union decreases the component count by one.

// If either Alice or Bob has more than one connected component,
// it is impossible for both to traverse the entire graph, so return -1.

// Otherwise, return the number of redundant (removable) edges.


class Solution {
public:
    vector<int> parentalice;
    vector<int> parentbob;
    int findalice(int i){
        if(parentalice[i] == i ) 
            return i ;
        return parentalice[i] = findalice(parentalice[i]);
    }
    int findbob(int i){
        if(parentbob[i] == i ) 
            return i ;
        return parentbob[i] =findbob(parentbob[i]);
    }
    bool unionalice(int i, int j){
        int rootI = findalice(i);
        int rootJ = findalice(j);
        if(rootI == rootJ)
            return false;// loop is there
        parentalice[rootJ] = rootI;
        return true;
    }
    bool unionbob(int i, int j){
        int rootI = findbob(i);
        int rootJ = findbob(j);
        if(rootI == rootJ)
            return false;// loop is there
        parentbob[rootJ] = rootI;
        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int removedEdges = 0;
        int alicecomp = n;
        int bobcomp = n;
        parentalice.resize(n+1);
        parentbob.resize(n+1);
        for(int i =1 ; i<= n ;i++){
            parentalice[i] = i;
        }
        for(int i =1 ; i<= n ;i++){
            parentbob[i] = i;
        }
        for(int i =0; i< edges.size() ; i++){
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
        
            if(type == 3){
            bool aliceUsed = unionalice(u,v);
            
            bool bobUsed = unionbob(u,v);
            
            if(aliceUsed|| bobUsed){
            //keep edge
            if(aliceUsed) alicecomp--;
            if(bobUsed) bobcomp--;
            } else{
            //remove edge
            removedEdges++;
            }}
        }
        for(int i =0; i< edges.size() ; i++){
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
        
            if(type == 2){
            
            bool bobUsed = unionbob(u,v);
            if(bobUsed){
            //keep edge
            bobcomp--;
            } else{
            //remove edge
            removedEdges++;
            }}
        }
        for(int i =0; i< edges.size() ; i++){
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
        
            if(type == 1){
            bool aliceUsed = unionalice(u,v);
            
            if(aliceUsed){
            //keep edge
            alicecomp--;
            } else{
            //remove edge
            removedEdges++;
            }}
        }
         
        if(alicecomp != 1 || bobcomp !=1)
            return -1;
            

     return removedEdges ;
        
    }
};
