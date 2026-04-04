class Solution {
public:
    void heapify(vector<int> &nums,int n, int i){
        int largest = i;
        int left = 2 *i+1 ;
        int right = 2 *i +2;
        
        if(left < n && nums[largest]< nums[left]){
            largest = left;
        }
        if(right < n && nums[largest]< nums[right]){
            largest = right;
        }
        if(largest != i){
            swap(nums[largest], nums[i]);
            heapify(nums,n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int t = nums.size();
        for(int i = t/2 - 1; i >= 0; i--){
            heapify(nums, t, i);
        }
        while(t > 1 ){
            swap(nums[0], nums[t-1]);
            t--;
            heapify(nums,t, 0);
        }
        return nums;

    }
};
