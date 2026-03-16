class Solution {
public:
    int longestValidParentheses(string s) {
        string answer = s;
        stack<int> st;
        stack<char> st1;
        for(int i = 0 ; i< s.length();i++){
            if(s[i] == '('){
                st.push(i);
                st1.push('(');
            }
            else if(s[i] == ')'){
                if(!st1.empty() && st1.top()== '('){
                    int num = i;
                    int num1 = st.top();
                    answer[num] = '*';
                    answer[num1]= '*';
                    st.pop();
                    st1.pop();
                }
               
            }
        }
        int count = 0 ;
        int i =0 ;
        int result=0;
        while( i< answer.length()){
            if(answer[i]=='*' ){
                count++;
            }
            else{
                if(count >result)
                result = count;
                count = 0;
            }
            i++;
        }
        result = max(result, count); 
        return result;
    }
};
