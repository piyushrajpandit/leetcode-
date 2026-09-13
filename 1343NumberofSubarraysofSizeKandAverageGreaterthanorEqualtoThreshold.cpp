class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left=0 ;
        int right = 0;
        int sum = 0;
        for (int i  =0; i<k; i++){
            sum += arr[i];
        }
        int count = 0;
        int avg = sum / k;
        right = k;
        if(sum >= threshold * k) count++;
        while(right <arr.size()){
            sum += arr[right];
            sum -= arr[left];
            left++;
            right++;
            if(sum >= threshold * k) count++;

        }
        return count;
    }
};
