 Pop the top element
Recursively reverse remaining stack
Insert the popped element at the bottom



//inset at bottom ka code 

stack<int> pushbottom(stack<int> & mystack , int s){
  if(s.empty()){
s.push(s);
return ;
}
  //top ko save karo 
int num  = s.top;
s.pop();
pushbottom(mystack , s);
  top ko wapas dalo
s.push(num);
  return mystack;
}




stack<int> reverse ( stack<int>& mystack){
if(mystack.empty()){
 return ;

  }

  int mum= mystack.top();
  mystack.pop();
  reverse(mystack);
  pushbotoom( mystack , num);
  
  

}

// time complexity o(n^2)

