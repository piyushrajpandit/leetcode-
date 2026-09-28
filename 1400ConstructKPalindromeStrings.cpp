class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        unordered_map<char, int > freq;
        for(char ch : s ){
            freq[ch]++;
        }
        int oddCount = 0;
        for(auto it : freq){
            if(it.second % 2 == 1){
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};
