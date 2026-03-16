// Question Next Smaller Element

// Given an array, find the next smaller element to the right for every element.

//   Input:
// [2, 1, 4, 3]

//  output [1, -1, 3, -1]


// 2 → next smaller = 1
// 1 → none → -1
// 4 → next smaller = 3
// 3 → none → -1


//   Logic

// For each element:

// Remove elements from stack that are greater or equal to current.

// The top of stack becomes the next smaller element.

// Push the current element into the stack.


vector<int> nextSmallest(vecotr<int>&arr, int n){
  stack<int> s ;
  s.push(-1);
  vector<int> answer(n);
  for(int i =n-1 ; i>= 0 ; i++){
    int curr =arr[i];
    while(s.top()>=curr){
      s.pop();
      
    }
    //answer is staack ka top 
    answer[i] = s.top();
    s.push(curr);
    return answer;
  }
}
