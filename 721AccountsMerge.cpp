// DSU is used to merge accounts that share at least one email.

// Each account index is a DSU node.
// parent[i] represents the parent of account i.

// emailToIndex stores:
// email -> first account index where the email appeared.

// While processing each account:
// - If an email is seen for the first time, store its account index.
// - If the email already exists, union the current account with
//   the previous account containing that email.

// After all unions:
// - Iterate through emailToIndex.
// - Find the root account for each email.
// - Group emails by their DSU root.

// For every group:
// - Get the person's name from accounts[root][0].
// - Sort all emails lexicographically.
// - Put the name first, followed by sorted emails.
// - Add the completed account to the answer.

// Path compression in find() makes DSU operations efficient.

// Time complexity:
// O(N * alpha(N) + E log E)
// where N = number of accounts and E = number of emails.

// Space complexity:
// O(N + E)

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
        if(rootI != rootJ)
            parent[rootJ]= rootI;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        vector<vector<string>> answer;
        unordered_map<string,int> map;
        for(int i=0; i< accounts.size(); i++){
            parent[i] = i;
        }
      
          for(int i=0; i< accounts.size();i++){
            for(int j =1; j< accounts[i].size();j++){
                string email = accounts[i][j];
              
                if(map.find(email) == map.end()) map[email] = i;
                else {
                    int previndex = map[email];
                    unite(previndex, i);
                }
            }
        }
 
        unordered_map<int, vector<string>> groups;
        for(auto &it : map){
                string email = it.first;
 
                int root = find(it.second);
                groups[root].push_back(email);
            }
        for(auto &it : groups){
            vector<string> result;
            int index = it.first;
            string name = accounts[index][0];
            vector<string> gmails = it.second;
            sort(gmails.begin(), gmails.end());
            result.push_back(name);
            for( int i =0 ; i< gmails.size(); i++) result.push_back(gmails[i]);
            answer.push_back(result);
        }
        return answer;
    }
};
