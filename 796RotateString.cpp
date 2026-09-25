// Logic:
// 1. If s and goal have different lengths, they cannot be rotations.
// 2. Try every index 'start' in s as a possible starting point of goal.
// 3. Only consider positions where s[start] == goal[0].
// 4. From that position, compare goal with s character by character.
// 5. Use j % s.size() so that when j reaches the end of s, it wraps back to index 0.
// 6. 'i' tracks the current character in goal, while 'j' tracks the current character in s.
// 7. If all characters match (i == goal.size()), goal is a valid rotation of s.
// 8. If no starting position works, return false.
//
// Example:
// s = "abcde", goal = "cdeab"
// Start at 'c' (index 2):
// c -> d -> e -> a -> b
// j moves: 2 -> 3 -> 4 -> 5 -> 6
// Using j % s.size(), it becomes: 2 -> 3 -> 4 -> 0 -> 1
// Therefore, the complete rotation matches and we return true.
Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        for( int start = 0 ; start < s.size() ; start++){
            if(s[start] != goal[0]){
                continue;
            }
            int i =0 ; 
            int j =start ;
        
        while( i< goal.size()){
            j = j% s.size();
        
            if(goal[i] != s[j]){
                break;
            }
        
            i++;
            j++;  
        }
            if(i == goal.size()){
                return true;
            }
            
        }
        return false;
    }
};
