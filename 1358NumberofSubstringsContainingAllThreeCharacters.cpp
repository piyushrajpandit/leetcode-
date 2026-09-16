class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0; 
        int right =0 ;
        int ans = 0;
        unordered_map<char, int> freq;
        

        while(right < s.length()){
            freq[s[right]]++;
          
            while(freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1){
                
                    if(freq[s[left]] == 1){
                        freq.erase(s[left]);
                    }
                    else{
                        freq[s[left]]--;
                    }
                
                left++;
            }
            ans +=  left;
            right++;

        }
        return ans;
    }
};
