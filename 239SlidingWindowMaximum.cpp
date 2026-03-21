class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        int N = nums.size();
        
  
        

        for(int i =0 ; i < N ;i++ ){
            //removal
            if((!dq.empty() )&&(dq.front() == i- k )){
                dq.pop_front();
            }
           
            // remove smaller elements from back
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // window fully formed, store answer
        if(i >= k - 1)
            ans.push_back(nums[dq.front()]); 

        }

return ans;

    }
};






//time limit aa gaya
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        int N = nums.size();
        int maxi =INT_MIN;
      

        for(int j =0 ; j <= N-k ;j++ ){
           
            //removal
                for(int i = 0 ; i < k ; i++){
                
                int element = nums[i+j];
                maxi = max(element,maxi);

                }
        ans.push_back(maxi);
         maxi = INT_MIN;
            
            // addition
            // yaha per confusion hai 
            
            //store answer
            
            

        }

return ans;

    }
};
