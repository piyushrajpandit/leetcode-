// #appraoch 1
// divide a array  in k parts but space optimized nahi hai 

// #approach 2
// top points to top element if stack 
// and next points either pevoius element or nrxt element of stack if arr[i] is filled withs some value
// else next point ot next free space 
// 1. find index of empty spot
//     int index = freespot ;
// 2. free spot update
//     freespot = next[index];
// 3. put the value
//     arr[index] = x;
// 4. update next
//     next[index] = top(m-1);
// 5. update top
//     top[m-1] = index;
   

class Nstack{
int *arr;
int *top;
int *next;

int N,S ;
int  freespot;

public :

//intitalize your data strucutre
  nstack{int N, int S){
  int n = N;
  int s = S;
  int arr = new int[s];
  int top = new int[n];
  int next = new int[s];

  //intialize top
for(int i = 0 ; i< n ;i++){
  top[i] = -1;
  }
//next ko intialize karo 
for(int i =0 ; i < s ; i++){
next[i] = i+1; 
}
//update last index to -1 
next[s-1] = -1 ;
 // intialize free spot 

int freespot = 0 ;
}
bool push(int x ,int m){

  //check that stack may not overflow
  if(freespot == -1 ){
    return false;
  }
    // find index 
    int index = freespot ;

    //update freespot 
    freespot = next[index];

    //insert element 
    arr[i] = x;

    //update next 
    next[index] = top[m-1];


    //update top
    top[m-1] = index;

    return true;
  }
int pop(int m){
  //check underflow condition
  if(top(m-1))= = -1){
    return -1;
  }
           int index = top[m-1];
           top[m-1]= next[index];
           next[index] = fresspot;
           freespot = index;
           return arr[index];
    
  }
}
