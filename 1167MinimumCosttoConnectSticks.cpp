// Problem Statement

// Given an array where each element represents the length of a rope, connect all ropes into one rope.

// Cost of connecting two ropes = sum of their lengths.
// Return the minimum total cost.

class solution 
{
public:
//function to return the minimum cost of connecting the ropes 
long long minCost(long long arr[], long long n){
  priority_queue<long long, vector<long long>,greater<long long> >pq;  
  for(int i =0; i<p ; i++){
    pq.push(arr[i]);
  }

  long long cost = 0;
  while(pq.cost() > 1){
  long long first = pq.top();
  pq.pop();
  
  long long second = pq.top();
  pq.pop();
  
  long long mergedLength() = first + second ;
  cost = cost + mergedLength;
  
  pq.push(maergedLength);
  }
  return cost;
}
};
