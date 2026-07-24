class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> maxHeap ;
       for(int i =0 ; i< nums.size() ; i++){

       maxHeap.push(nums[i]);
       }
       for(int i =0; i< k-1 ; i++){
        maxHeap.pop();
       }
       int answer = maxHeap.top();
       return answer;
    }
};
