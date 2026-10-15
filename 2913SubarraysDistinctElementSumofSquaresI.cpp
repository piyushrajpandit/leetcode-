class Solution {
public:
    int sumCounts(vector<int>& nums) {
         int answer = 0;
         for(int left = 0 ; left < nums.size() ;left++){
            unordered_set<int> st;

            for(int right = left ;right < nums.size() ; right++){
                st.insert(nums[right]);
                int count = st.size();
                answer += count* count;
            }
         }
      
        return answer;
    }
};
