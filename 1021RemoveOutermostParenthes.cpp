//*second time done this question only simple thing put the first braces in stack 
//and if the second braces comes if stack is not wmpty mark the index of it and after removing one if 
//    stack became empty make both s[i] and s[older index ] =* and return answer by removing * from ansawer*//
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
