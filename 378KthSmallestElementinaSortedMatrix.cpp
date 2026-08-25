/*
LeetCode 378 - Kth Smallest Element in a Sorted Matrix

Approach:
Use a min-heap to perform a k-way merge of all sorted rows.

1. Each row is already sorted.
2. Put the first element of every row into a min-heap.
   Store three things:
       {value, row, column}

3. Remove the smallest element from the heap.
   This is the next smallest element in the matrix.

4. Increment count.
   If count == k, return the current value.

5. After removing an element from a row, insert the next element
   from the SAME row into the heap.

   Example:
       removed: {5, 0, 1}
       next:    {9, 0, 2}

6. Continue until the kth smallest element is found.

Min-heap declaration:
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > rank;

Why store row and column?
    After removing matrix[row][column],
    we need to know where the next element of that row is:
        matrix[row][column + 1]

Important:
    Check column + 1 < cols before accessing the next element.

Example:
    [1,  5,  9]
    [10, 11, 13]
    [12, 13, 15]

Initial heap:
    (1,0,0)
    (10,1,0)
    (12,2,0)

Remove 1 → insert 5
Remove 5 → insert 9
Remove 9 → row 0 is finished
Continue with other rows.

Complexity:
    Time:  O(k log n)
    Space: O(n)

where n = number of rows.
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int ,int, int >>, greater<tuple<int, int,int>>
            > rank;
        for(int i =0; i< matrix.size(); i++){
            rank.push({matrix[i][0],i ,0});
        }
       
        while(!rank.empty()){
            auto [value, row , column] = rank.top();
            count++;
            rank.pop();
            if(count == k)
                return value;
            if(column + 1 < cols){

                rank.push({matrix[row][column+1],row, column+ 1});
              

            }
        }
    return -1;
    }
};
