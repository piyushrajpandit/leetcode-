class Solution {
public:
    int answer = 0;

    void solve(vector<int>& nums1, vector<int>& nums2,
               int i, int j, int count) {

        if (i < 0 || j < 0) {
            answer = max(answer, count);
            return;
        }

        if (nums1[i] == nums2[j]) {
            solve(nums1, nums2, i-1, j-1, count+1);
        }
        else {
            answer = max(answer, count);
        }

        // Explore other alignments
        solve(nums1, nums2, i-1, j, 0);
        solve(nums1, nums2, i, j-1, 0);

        answer = max(answer, count);
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        answer = 0;
        solve(nums1, nums2, n-1, m-1, 0);

        return answer;
    }
};





class Solution {
public:
    int answer = 0;

    int solve(vector<int>& nums1, vector<int>& nums2,
              int i, int j, vector<vector<int>>& dp) {

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (nums1[i] == nums2[j]) {
            dp[i][j] = 1 + solve(nums1, nums2, i-1, j-1, dp);
        }
        else {
            dp[i][j] = 0;
        }

        answer = max(answer, dp[i][j]);

        return dp[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                solve(nums1, nums2, i, j, dp);
            }
        }

        return answer;
    }
};
