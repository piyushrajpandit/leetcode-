class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int maxCount = 0;
        int index = 0;
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; i++) {
            int count = 0;
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            if (count > maxCount) {
                index = i;
                maxCount = count;
            }
        }
        ans.push_back(index); ans.push_back(maxCount);
        return ans;
    }
};
