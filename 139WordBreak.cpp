class Solution {
public:
    bool solve(string s, unordered_set<string>& dict, int i ){
        if(i == s.size()){
            return true;
        }
        for(int j = i; j< s.size(); j++){
            string temp = s.substr(i, j -i +1);
            if(dict.find(temp)!= dict.end()){
                if(solve(s,dict, j+1)){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i =0 ; i< wordDict.size() ;i++){
            dict.insert(wordDict[i]);
        }
        return solve(s,dict, 0);

    }
};

class Solution {
public:
    bool solve(string s, unordered_set<string>& dict, int i, vector<int>& dp ){
        if(i == s.size()){
            return true;
        }
        if(dp[i] != -1)
            return dp[i];

        for(int j = i; j< s.size(); j++){
            string temp = s.substr(i, j -i +1);
            if(dict.find(temp)!= dict.end()){
                if(solve(s,dict, j+1,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() , -1);
        return solve(s,dict, 0,dp);

    }
};
