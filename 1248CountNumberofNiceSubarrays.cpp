class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]  =1 ;

       
        int oddcount = 0;
        int ans = 0;

        for(int num : nums){
            if(num %2 != 0)
                oddcount++;
            if(freq.find(oddcount - k )!= freq.end())
                ans += freq[oddcount - k];
            freq[oddcount]++;
        }
            
        
        
        return ans;
    }
};
