class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> result;
        for(int num1 : nums1){
            for(int num2 : nums2){
                if(num1 == num2){
                    result.insert(num1);
                    break;
                }
            }
        }
        vector<int> answer;
        for(auto temp : result)
            answer.push_back(temp);
        return answer;
    }
};
