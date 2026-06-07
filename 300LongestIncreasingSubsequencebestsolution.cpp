class Solution {
public:
    int solve(vector<int> &a, int n){

       if(n==0 )
       return 0;

       vector<int> ans;
       ans.push_back(a[0]);

       for(int i=1; i<n; i++){
        if(a[i] > ans.back())
            ans.push_back(a[i]);
        else{
            //find index of just bada element in ans 
            int index = lower_bound(ans.begin(), ans.end(), a[i])- ans.begin();
            ans[index] = a[i];

        }
       }
       return ans.size();

    }
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size(); 
        
         return solve(nums, n);
     }

    
};
