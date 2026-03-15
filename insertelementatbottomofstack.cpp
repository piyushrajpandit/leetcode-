stack<int> solve(stack<int> & mystack, int s){
  //base case
if(s.empty()){
s.push(s);
return ;
}
  //top ko save karo 
int num  = s.top;
s.pop();
solve(mystack , s);
  top ko wapas dalo
s.push(num);
}

stack<int> pushbottom(stack<int> & mystack , int s){
  solve(stack,x);
  return mystack;
}
