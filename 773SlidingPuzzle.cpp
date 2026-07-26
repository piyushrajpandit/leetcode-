// #this question is done by ai because it was so complex so much small parts
// still i can not write this code manually 
// BFS Approach
// 1. Convert the board into a string representation.
// 2. Use a queue to store {current state, number of moves}.
// 3. Use a visited set to avoid revisiting the same board.
// 4. For each state, find the position of '0'.
// 5. Generate all possible next states by swapping '0' with its valid neighbors.
// 6. If a new state has not been visited, push it into the queue.
// 7. The first time we reach "123450", return the number of moves.
//
// Time Complexity: O(6!) ≈ O(720)
// Space Complexity: O(6!)
/*
here what ever i try to write was somkind of wrong 
first bfs is used is hard to know how will you apply bfs on moves but still lets moves further 
second 
What is an unordered_set?

It is a container that

Stores unique values.
Does not keep them in order.
Allows searching in O(1) average time.

it is used to mark visited 
third smard move is createing moves all the possible steps from that point this i can not thing if i give 10 days also 

fouth how gracefully we applied and make a move i was thinking of recussion an other things but look at this 
  for(int next : moves[zeroIndex]){
                string newState = state;
                swap(newState[zeroIndex], newState[next]);
                if(!visited.count(newState))
                    {
                        visited.insert(newState);
                        q.push({newState,step+1});
                    }
            }
*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string element;
        for(int i =0; i< board.size(); i++){
            for(int j= 0; j< board[0].size(); j++){
                element.push_back(board[i][j] +'0');
            }
        }

        queue<pair<string,int>> q; 
        unordered_set<string> visited;
        vector<vector<int>> moves = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
       visited.insert(element);
        q.push({element,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            string state = curr.first;
            int step = curr.second;
            
         
            if(state=="123450")
                return step;
            
            int zeroIndex;

            for(int i = 0; i < 6; i++){
                if(state[i] == '0'){
                    zeroIndex = i;
                    break;
                }
            }
            for(int next : moves[zeroIndex]){
                string newState = state;
                swap(newState[zeroIndex], newState[next]);
                if(!visited.count(newState))
                    {
                        visited.insert(newState);
                        q.push({newState,step+1});
                    }
            }
            
        


        }
        return -1;
    }
};

