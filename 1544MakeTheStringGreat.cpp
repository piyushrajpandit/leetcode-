/*
abs(answer.back() - ch) == 32
'a' = 97
'A' = 65

97 - 65 = 32
*/
class Solution {
public:
    string makeGood(string s) { 
        
        string answer;
        for( char ch : s){
            if( !answer.empty() && abs(answer.back() - ch) == 32){
                answer.pop_back();
            }
            else{
                answer.push_back(ch);
            }
        }
        return answer;
    }
};
