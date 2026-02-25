class Solution {
public:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int count = 0;

     
        for(int i = start + 1; i <= end; i++) {
            if(nums[i] <= pivot)
                count++;
        }

        int pivotIndex = start + count;
        swap(nums[start], nums[pivotIndex]);

        int i = start;
        int j = end;

        while(i < pivotIndex && j > pivotIndex) {

            while(nums[i] <= pivot)
                i++;

            while(nums[j] > pivot)
                j--;

            if(i < pivotIndex && j > pivotIndex)
                swap(nums[i++], nums[j--]);
        }

        return pivotIndex;
    }

    void quickSort(vector<int>& nums, int start, int end) {
        if(start >= end)
            return;

        int p = partition(nums, start, end);

        quickSort(nums, start, p - 1);
        quickSort(nums, p + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
