class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int i =0 ; i< nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i =0 ;i< nums.size();i++){
            if(freq[nums[i]] == 1){
                ans.push_back(nums[i]);
            } 
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorValue = 0 ;
        for(int i =0 ;i< nums.size() ;i++){
            xorValue ^= nums[i];
        }
        unsigned int rightmost = (unsigned int)xorValue & -(unsigned int)xorValue;

        int first = 0 ;
        int second = 0;
        for(int i=0 ; i< nums.size() ;i++){
            if(nums[i] & rightmost){
                first ^= nums[i];
            }
            else{
                second ^= nums[i];
            }
        }
        return {first, second};
    }
};
