class Solution {
public:
    vector<string> answer;
    void solve( string &s, int start){
      
        if( start == s.size()){
            answer.push_back(s);
            return ;
        }
        if(isalpha(s[start])){
            s[start] = tolower(s[start]);
            solve(s, start + 1);

            s[start] = toupper(s[start]);
            solve(s ,start + 1);
        }
        else{
            solve(s, start + 1);
        }

    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
       return answer; 
    }
};
