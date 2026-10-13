class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>> dq;
        for(int i =0 ; i< nums.size(); i++){
            dq.push(nums[i]*nums[i]);
        }
        long long ans= 0;
        int n = nums.size();
        
        for(int i =0 ; i< n/2; i++){
           int temp=   dq.top();
           dq.pop();
           ans -= temp ;

        }
        while(!dq.empty()){
            int temp=  dq.top();
            dq.pop();
            ans += temp ;
        }
        return ans;
        
    }
};
