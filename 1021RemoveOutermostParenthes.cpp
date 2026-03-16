class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = s; 
        stack<int> st;
        for ( int i = 0 ; i< s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if( s[i] == ')'){
                if(!st.empty()){
                    
                    int num = st.top();
                    
                    

                    st.pop();
                    if(st.empty()){
                        answer[i] = '*';
                        answer[num] = '*';
                    }
                }
            }
        }
        string result = "";
    for(char ch : answer){
        if(ch != '*')
            result.push_back(ch);
    }
    return result;
    }
};
