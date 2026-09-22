// Find all lucky numbers in the matrix.
// A lucky number is the smallest element in its row
// and the largest element in its column.
//
// For each row:
// 1. Find the minimum element of the row using min_element().
// 2. Find the column index of that minimum using:
//    min_element(...) - matrix[i].begin().
// 3. Check every element in that column.
// 4. If no element is greater than the row minimum,
//    then it is the maximum in its column, so it is a lucky number.
// 5. Add it to the answer vector.
//
// Finally, return the vector containing all lucky numbers.
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> lucky;

        for(int i =0 ; i< matrix.size() ; i++){
            int rowMin = *min_element(matrix[i].begin() , matrix[i].end());
        
            int col = min_element(matrix[i].begin() , matrix[i].end()) - matrix[i].begin();
            bool islucky = true;
            for(int j =0 ; j< matrix.size() ; j++){
                if(matrix[j][col] > rowMin){
                    islucky = false;
                    break;
                }
            }
            if(islucky){
                lucky.push_back(rowMin);
            }
        }
        return lucky;
    }
};
