// #approach 
// quesue se one by one element nikalo 
// stack me dalo 
// stack se nikal0
// queue me dalo
// time o(n)
// space o(n)

// #approach 2 
// recurssion 
stack<int>s ;
while(!q.empty()){
  int element = q.front();
q.pop();
  s.push(element);
}
while(!s.empty())
  element = s.top();
s.pop();
q.push(element);
}



