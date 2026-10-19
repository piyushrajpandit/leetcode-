class Solution {
public:
    void backtrack(string s ,vector<string>& answer,int index,  string temp,int parts ){

        if(parts == 4 && index == s.size()){
            temp.pop_back();
            answer.push_back(temp);
            return ;
        }
        if(parts == 4 || index == s.size()){
            return ;
        }
      
        for(int len = 1; len <= 3 && index + len <= s.size(); len++){
            string part = s.substr(index, len);
            if(len > 1 && part[0] == '0'){
                break;
            }
            int number = stoi(part);
            if(number > 255){
                break;
            }
            backtrack(s,answer, index+ len, temp+ part+".", parts+1);
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        if(s.size() < 4 || s.size() > 12){
            return answer;
        }
        backtrack(s,answer,0, "" ,0);
        return answer;
    }
};
