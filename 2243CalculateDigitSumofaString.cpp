class Solution {
public:
    string digitSum(string s, int k) {
        string t;
        if(s.size() <= k){
            return s;
        }
        for(int i =0 ; i< s.size() -2; i+3){
            int temp;
            temp += s[i] +'0';
            if(s[i+1])
            temp += s[i+1] +'0';
            if(s[i+2])
            temp += s[i+2] +'0'; 
            t += temp + 'a';
        }
        return digitSum(t, k);
    }
};
