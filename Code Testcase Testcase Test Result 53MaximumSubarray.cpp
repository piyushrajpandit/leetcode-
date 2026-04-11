kadne algorithm
actually you have to move from right part or left part and store two things best sum and sum at curretn position 
make two variable one is the sum_including current in which you store maximum of last plus this element and only this element 
this is to make change in value 
and second thing you have to do is take max of last max and sumincluding current one element 

 class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()== 0){
            return 0;
        }
        int sum_max = nums[0];
        int sum_including_current = nums[0];

        for(int i =1; i < nums.size() ; i++){
            int n = nums[i];
            sum_including_current = max(sum_including_current+n,n);
            sum_max = max(sum_max,sum_including_current);
        }
        return sum_max;
    }
};
