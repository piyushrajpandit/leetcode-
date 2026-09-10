class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        int i = 0;
        while (i + m <= n) {
            int j = 0;
            vector<int> dp(26, 0);
            vector<int> dp2(26, 0);

            for (int j = 0; j < m; j++) {
                dp[p[j]-'a']++;
            }

            for (int k = 0; k < m; k++) {
                dp2[s[i + k] - 'a']++;
            }
            int t;
            for (t = 0; t < 26; t++) {
                if (dp2[t] == dp[t])
                    continue;
                else
                    break;
            }
            if (t == 26) {
                ans.push_back(i);
            }

            i++;
        }
        return ans;
    }
};
