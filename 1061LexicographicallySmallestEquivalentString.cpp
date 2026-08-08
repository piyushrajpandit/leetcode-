// Use DSU to group equivalent characters into sets.

// Each character 'a' to 'z' is represented by an index 0 to 25.
// For every pair (s1[i], s2[i]), union their sets.

// Unlike normal DSU, we always make the lexicographically
// smaller root the parent. This ensures that the root of every
// set is the smallest character in that equivalence class.

// Use path compression in find() to efficiently find the root.

// For every character in baseStr:
// 1. Convert it to an index.
// 2. Find its DSU root.
// 3. Convert the root back to a character.
// 4. Add it to the answer.

// The resulting string is lexicographically smallest because
// every character is replaced by the smallest equivalent character.

class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i,int j){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI != rootJ){
            if(rootI < rootJ)
                parent[rootJ] = rootI;
            else
                parent[rootI] = rootJ;
        }

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string answer;
        parent.resize(26);
        for(int i =0; i< 26; i++)
            parent[i] = i;

        for(int i =0 ; i< s1.size(); i++){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            unite(a,b);
        }
        for(auto ch : baseStr){
            int index = ch - 'a';
            int parentindex = find(parent[index]);
            char ch1= parentindex + 'a';
            answer += ch1;
        }
        return answer;
    }
};
