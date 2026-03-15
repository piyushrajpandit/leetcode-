void sortedInsert(stack<int>mystack , int num){
//base case 
if(mystack.empty() ||(s.empty() && s.top< num)){
mystack.push(num);
return ;
}
int n = mystack.top();
stack.pop();
sortedinsert(mystack,num);
mystack.push(n);
}


#appraoch 
top element nikalo aur unsko store kar ko 
fir se ek elemnet nikalo aur store kar ko sare element nikal gaye 
ab ek ek kar ke un element ko andar dalo lekin sort way me 
sort karne ke liye check karo jo element dal rahe ho wo top se badi hai to elememt dal do 
nahi to ek element nikal lo 
fir sort function chalao 
aur jai wapas aana to jo element nikale wo dal dena 


void sortstack (stack<int> mystack ){

//base case 
if(mystack.empty()){
return }
int num = mystack.top();
stack.pop();
sortstack(mystack);
sortedinserted(mystack,num)
}
