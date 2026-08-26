/*
    Approach:
    - Start with the first row as the initial possible sums.
    - Process each remaining row one by one.
    - For every previous sum, add every element of the current row
      to generate all possible new sums.
    - Sort the new sums.
    - Keep only the K smallest sums because we only need the Kth
      smallest final sum.
    - Repeat this process for all rows.
    - At the end, sums[k - 1] gives the Kth smallest sum.

    Key Idea:
    After processing each row, `sums` contains the K smallest
    possible sums using all rows processed so far.

    Time Complexity:
    O(rows * k * cols * log(k * cols))

    Space Complexity:
    O(k * cols)
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = mat[0];
        int rows = mat.size();
        int cols = mat[0].size();


        for(int i = 1 ; i < rows; i++){
            vector<int> sums2;
            for(int prev_sum : sums){
                for(int j =0 ; j< cols ; j++){
                    sums2.push_back(prev_sum + mat[i][j]);
                }
            }
        sort(sums2.begin(), sums2.end());
        if(sums2.size() > k){
            sums2.resize(k);
        }
        sums = sums2;

        }
        return sums[k-1];
    }
};

/*
For every sums[i]
       ↓
start with row[0]
       ↓
when popped
       ↓
move to row[1]
       ↓
when popped
       ↓
move to row[2]
*/

class Solution {
public:
    vector<int> merge(vector<int> sums , vector<int> row , int k){
        priority_queue<pair<int ,int>, vector<pair<int,int >>, greater<pair<int , int>> >pq;
        
        for(int i =0 ; i< sums.size() ; i++){
            pq.push({sums[i]+ row[0], 0});
        }
        vector<int> result;
        while(!pq.empty() && result.size() < k){
            auto [ sum, j] = pq.top();
            pq.pop();
            result.push_back(sum);
            if(j + 1 < row.size()){
                pq.push({sum - row[j] + row[j+1] ,j+1});
            }
        }
        return result;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = mat[0];

        vector<int> sum;
        for(int i = 1 ; i < mat.size(); i++){
          sums = merge(sums ,mat[i] ,k);
        }
      
        return sums[k-1];
    }
};
