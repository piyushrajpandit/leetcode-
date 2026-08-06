/*
Approach:
1. Initialize DSU (Disjoint Set Union) for 26 lowercase letters.
2. First pass:
   - Process all "==" equations.
   - Union the sets of both variables.
3. Second pass:
   - Process all "!=" equations.
   - If both variables belong to the same set (find(x) == find(y)),
     the equations are contradictory, so return false.
4. If no contradiction is found, return true.

Time Complexity: O(N * α(26)) ≈ O(N)
Space Complexity: O(26) ≈ O(1)

where N = number of equations and α is the inverse Ackermann function.
*/

class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i)
            return i ;
        return parent[i] =find(parent[i]); 
    }
    void unite(int i , int j){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI != rootJ)
        
         parent[rootJ] = rootI;
       
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for( int i =0; i < 26; i++){
           parent[i] = i; 
        }
        for(int i=0 ; i< equations.size() ; i++){
            if(equations[i][1] == '='){
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                unite(x,y);
            }

        }
         for(int i=0 ; i< equations.size() ; i++){
            if(equations[i][1] == '!'){
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                 
                if(find(x) == find(y))
                    return false;
            }

        }
        return true;
    }

};
