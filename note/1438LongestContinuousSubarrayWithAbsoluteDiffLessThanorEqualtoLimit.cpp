 class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i =0 , j= 0 , maxLen= 0;
        deque<pair<int , int>> maxDeq , minDeq;
        while(j<n){
            while(!maxDeq.empty() && maxDeq.back().first < nums[j]) maxDeq.pop_back();
            maxDeq.push_back({nums[j], j});
            while(!minDeq.empty() && minDeq.back().first > nums[j]) minDeq.pop_back();
            minDeq.push_back({nums[j], j});

            int diff = maxDeq.front().first - minDeq.front().first;
            while(i < j && diff > limit){
                i = min(maxDeq.front().second, minDeq.front().second) +1;
                while(!maxDeq.empty() && maxDeq.front().second < i)maxDeq.pop_front();
                while(!minDeq.empty() && minDeq.front().second < i)minDeq.pop_front();
                diff = maxDeq.front().first - minDeq.front().first;

            }
            maxLen = max(maxLen , j - i + 1);
            j++;
        }
     return maxLen;
    }
};
