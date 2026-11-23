class Solution {
public:
    bool correct(string a, string b){
        if(a.length()+1  != b.length()){
            return false;
        }
        int i =0 ;
        int j =0;
        bool used = false;
        while(j< b.length() ){
            if(i<a.length() && a[i] == b[j]){
                i++;
                j++;
            }
            else if (used == false){
                used = true;
                j++;
            }
            else{
                return false;
            }
        }
        return i == a.length();
    }
    int solve(vector<string>& words,int index ,vector<int>&dp){
        if(dp[index] != -1){
            return dp[index];
        }
        
        int maxlen = 1;
        for(int i=index +1 ; i< words.size() ;i++){
            if(correct(words[index], words[i])){
                maxlen = max(maxlen, 1+ solve(words, i,dp));
            }
        }
        return dp[index] =maxlen;
    }
    int longestStrChain(vector<string>& words) {
     
        sort(words.begin(), words.end(),[](string &a, string &b){
            return a.length() < b.length();
        });
        vector<int> dp(words.size() ,-1);
        int answer =1;
        for(int i =0 ; i< words.size() ;i++){
            
            answer= max(answer, solve(words,i,dp));
        }
        return answer;
    }
};
