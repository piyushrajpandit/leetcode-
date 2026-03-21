vector<long long> printFristNegativeInteger(long long int A[], long long int N, long long int K){
  deques<long long int >dq;
  vector<long long>ans;
  for(int i = 0 ; i < K; i++){
if(A[i] < 0 ){
  dq.push_back(i);
}
  }
//store answer for first k sized qindow
if(dq.size()> 0){
ans.push_back(A[dq.front()]);
}
else{
ans.push_back(0);
}
//process for remaning window 
for(int i =k ; i< N; i++){
if(!dq.empty() && i-dq.front() >=k){
dq.pop_front();
}
//addition
if(A[i] <0){
dq.push_back(A[dq.front()]);
}
else{
ans.push_back(0);
}
}
return ans;
}


  
