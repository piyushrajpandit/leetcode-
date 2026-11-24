class Solution {
public:
    
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int answer =0;
         for(int i = 0 ; i< n; i++){
            long long prod = 1;
            long long g = 0;
            long long l =1;
            for(int j = i; j< n; j++){
                if(prod > LLONG_MAX/ nums[j]){
                    break;
                }
                prod *= nums[j];
                g= gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if(prod == g*l){
                    answer = max(answer, j-i+1);
                }
            }
         }
         return answer;
    }
};
