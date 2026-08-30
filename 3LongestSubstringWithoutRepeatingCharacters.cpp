class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count= 0;
        int ans = 0;
        int left =0;
        unordered_map<char, int> rank;
        for (int right = 0; right < s.size(); right++) {
            if (rank.find(s[right]) != rank.end()) {
                left = max(left ,rank[s[right]]+ 1);
                
            } 
            rank[s[right]] = right;
            count =right - left +1;
            ans =max(ans, count);
        }
        return ans;
    }
}
// Sliding Window:
// left  -> starting point of current substring
// right -> expands the substring
// map   -> remembers the last position of each character
// duplicate -> move left past its previous position
// ans -> maximum window size
