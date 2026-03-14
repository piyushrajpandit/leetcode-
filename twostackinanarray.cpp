// #apprach 
// 1. push empty space then pop 
// 2. pop check element if their then pop
// 3. stack one left to right 
// 4. second stack insert from right to left 

class twostack{
int* arr ;
int top1 ;
int top2  ;
int size ; 
pubic :
twostack(int s){
this->size = s;
top1  = -1;
top2 = s;
arr = new int[s];
}
void push1(int num){
  if((top2- top1) > 1){
    top1++;
    arr[top1]= num;
  }
  else{
    printf("stack overflow");
  }
  
  
}
void push2(int num){
   if((top2- top1) > 1){
    top2---;
    arr[top2]= num;
  }
  else{
    printf("stack overflow");
  }
}
int pop1 (){
  if(top1>=0){
    int ans = arr[top1];
    top1--;
    return ans;
  }

  else{
    return -1 ;
  }
    
  
}
int pop2 (){
  if(top2< s){
    int ans = arr[top2];
    top2++;
    return ans;
  }

  else{
    return -1 ;
  }
    
  
}

};
