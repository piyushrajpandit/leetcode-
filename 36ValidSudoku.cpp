class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int j =0; j< 9; j++){
        unordered_map<int, int> dq;
        for(int i=0 ; i< 9 ; i++){
            int temp = board[i][j];
                if(temp == '.')
                continue;
            if(dq.find(temp) == dq.end()){
                dq[temp]++;
            }
            else{
                return false;
            }
        }
        }
        for(int j =0 ; j< 9 ;j++){
        unordered_map<int, int> dq1;
        for(int i=0 ; i< 9 ; i++){
            int temp = board[j][i];
                if(temp == '.')
                continue;
            if(dq1.find(temp) == dq1.end()){
                dq1[temp]++;
            }
            else{
                return false;
            }
        }
        }
        int i =0 ;
        int j =0 ;
        for(int i =0 ;i< 9; i+= 3){
            for(int j =0; j< 9; j+= 3){
            unordered_map<int, int> dq3;
            for(int k =0 ; k<3; k++){
                for(int q =0 ; q < 3 ; q++){
                     int temp = board[i+k][j+q];
                         if(temp == '.')
                        continue;
                    if(dq3.find(temp) == dq3.end()){
                        dq3[temp]++;
                    }
                    else{
                        return false;
                    }
                }
            }
            }
        }
        
        return true;
    }
};
