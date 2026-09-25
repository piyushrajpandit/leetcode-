class Solution {
public:
    int count = 0;
    bool palindrom(const string& s, int left , int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(const string& s, int start ){
       if(start == s.size()){
         return;
            }
        for(int right = start ; right < s.size() ; right++){
            if(palindrom(s, start ,right)){
                count++;
       
            }
        }
                solve(s, start  + 1 );
    }
    int countSubstrings(string s) {
      
     
        solve( s, 0 );
        return count;
    }
};
