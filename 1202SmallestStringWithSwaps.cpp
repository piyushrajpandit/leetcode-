/*
pairs
 ↓
DSU connects indices
 ↓
find(i) gives component/root
 ↓
root → indices
root → characters
 ↓
sort characters
 ↓
smallest character → smallest index
 ↓
lexicographically smallest string


*/

class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI < rootJ)
            parent[rootJ] = rootI;
        else
            parent[rootI] = rootJ;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.resize(s.length());
        for(int i =0; i < s.length(); i++){
            parent[i] = i;
        }
      
      
        
        for( auto pa : pairs){
            
            int i = pa[0];
            int j = pa[1];
            unite(i,j);
        }
       
        unordered_map<int, vector<int>> indexMap;
        unordered_map<int, vector<char>> charsMap;
        for(int i =0; i< s.length(); i++){
            int root = find(i);
            indexMap[root].push_back(i);
            charsMap[root].push_back(s[i]);
         
        }
        for(auto &it : charsMap){
            sort(it.second.begin(), it.second.end());
        }
        for(auto &it: indexMap){
            int root = it.first;
            vector<int> & indices = it.second;
            vector<char> & chars = charsMap[root];
            sort(chars.begin(), chars.end());
            for(int i=0 ; i< indices.size(); i++){
                s[indices[i]] = chars[i];
            }
        }
       
        return s;
    }
};
