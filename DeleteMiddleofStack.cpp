void  solve(stack<int>inputstack ,int  count ,int N){
  //base case 
  if(count == size/2){
    inputstack.pop();
    return ; 
  }


  int num = inputStack.top();
  inputStack.pop();

  //recursive call
  solve(inputstack , count +1, N);
  inputStack.push(num);
}

// simple chiz hai count badha rahe hai aur ek element hata rahe hai 
// hatye element ko store bhi kar rahe hai 
// jab count size ka half ho jata hai to uska top kko delete karte hai 
// aur jo pehle hatye the usko add kar rahe hai 
// niche main function hai 


void delete (stack<int>insputstack , N ){
  int count = 0 ; 
  solve(inputstack , count , N);
  }
  
