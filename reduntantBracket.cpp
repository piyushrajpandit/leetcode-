// #approach 
// reduntant bracket means no operator to consume 
// simple extra bracket
// 1. agar opening bracket hai ya koi operator hai to use stack me dal do 
// 2. nahi to check karo closing breacket hai to stack ka top agar koi operator hai kya agar hai to false  karo reduntant ko 
// 3. aur top element hata do 
// 4. agar true hai reduntant ke bar bhi to true return kar do 
// 5. nahi to ek character age badho 
  



class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st ; 
        for (int i = 0 ; i< s.length() ; i++){
            char ch = s[i];
            if( ch == '(' || ch == '+' || ch == '-'|| ch == '*' || ch == '/'){

                    st.push(char);
            }
            else{
                //ya to closing hai ya lowercase 
                if(ch == ')'){
                    bool isRedundant = true;
                    while(st.top != '('){
                        char top = st.top();
                        if(top == '+' || top == '-'|| top == '*' || top == '/'){
                            isRedundant = false;
                        }
                        st.pop();
                    }
                    if(isReduntant == true){
                        return true;
                        st.pop();
                    }
                }
            }
        }
        return false;
    }
};
