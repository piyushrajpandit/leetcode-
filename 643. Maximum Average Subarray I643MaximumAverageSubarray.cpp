class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k;
        double ans = INT_MIN;
        double sum = 0 ;
        for(int i =0 ; i< k ; i++){
            sum += nums[i];
        }
        double avg = sum / k;
        ans = max(ans ,avg);
        while(right < nums.size()){
            sum += nums[right];
            sum -= nums[left];
            avg = double (sum) / k;
            ans = max(ans, avg);

            right++;
            left++;
        }
    return ans;
    }
};
