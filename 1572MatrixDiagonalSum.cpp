class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int index = row-1;
        int sum = 0;
        for(int i =0 ; i< row ; i++){
            for(int j =0 ; j < col ; j++){
                if(i == j ) 
                    sum += mat[i][j];
                if((i + j == index )&& i != j ) sum += mat[i][j];
            }
        }
        return sum ;
    }
};
