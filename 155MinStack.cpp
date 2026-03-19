class MinStack {
public:
    long long mini = LLONG_MAX; 
    stack<long long> s;  
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                s.push(2*(long long)val - mini);  
                mini = val;
            }
            else{
                s.push(val);

            }
        }
    }
    
    void pop() {
        if(s.empty()){
            return  ;
        }
        else{
             long long curr = s.top();
            // int curr = s.top();
            s.pop();
            if(curr > mini){
                // return curr;
            }
            else{
                
                
                mini =  2*mini - curr;
               
            }
        }
            if(s.empty()){
        mini = LLONG_MAX;  // ✅ reset mini when stack empty
    }
    }
    
    int top() {
        if(s.empty()){
            return -1 ;
        }
        else{
            // int curr = s.top();
             long long curr = s.top();  // ✅
            if(curr < mini){
                // return mini;
                  return (int)mini;      // ✅ cast back to int for return
            }
            else{
                // return curr;
                  return (int)curr; 
            }

        }
    }
    
    int getMin() {
        if(s.empty())
        return -1 ;

        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
