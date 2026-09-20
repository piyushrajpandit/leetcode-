class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = 0;
        vector<int> rows;
        vector<int> cols;
        for( i =0 ; i< row; i++){
            for(  j =0; j < col ; j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i =0 ; i< rows.size() ;i++){
            for(int  j  =0 ; j < col; j++){
                matrix[rows[i]][j] = 0 ;
            }
        }
        for(int  j  =0 ; j < cols.size(); j++){
            for(int i =0 ; i< row ;i++){
                matrix[i][cols[j]] = 0 ;
            }
        }
  
    }
};
