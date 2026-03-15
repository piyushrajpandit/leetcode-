class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st ; 
        string answer= s;
        for (int i = 0 ; i< s.length() ; i++){
            char ch = s[i];
            
            if( ch == '(' ){

                    st.push(i);
                   
            }
            else if(ch == ')' ){
                if(!st.empty()){
                    st.pop();
                }
            
            
                else{
                    answer[i] = '*';
                }
            }
                
               
         }
    while(!st.empty()){
        answer[st.top()] = '*';
        st.pop();
    }
    string result = "";
    for(char ch : answer){
        if(ch != '*')
            result.push_back(ch);
    }
    return result;
}
      
       
    
};
