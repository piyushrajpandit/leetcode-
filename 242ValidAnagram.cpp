class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dq(26,0);
        vector<int> dq2(26,0);
        if(s.size() != t.size())
            return false;
        for(int i =0 ; i< s.size(); i++){
            dq[s[i]-'a']++;
            dq2[t[i]-'a']++;
        }
        for(int i=0 ;i < 26 ; i++){
            if(dq[i] != dq2[i]) return false;
        }
        return true;
    }
};
