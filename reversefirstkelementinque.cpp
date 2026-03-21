queue<int> modifyQueue(queue<int> q, int k){
  //algo 
//step1 pop first k from q and put in stack
stack<int> s;
for(int i =0 ; i< k; i++){
int val = q.front();
q.pop();
s.push(val);
}

//step 2 : fetch from stack and push int q 
while(!s.empty()){
int val = s.top();
s.pop();
q.push(val);
};
//step 3 fetch first(n-k) element from Q ans push back
int t  = q.size()-k;
while(t--){
 int val = q.front();
q.pop();
q.push(val);
}
return q; 
}
